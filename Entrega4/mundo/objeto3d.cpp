#include "objeto3d.h"
#include "cohen_sutherland.h"
#include <cmath>

Objeto3D::Objeto3D(QString nome) {
    this->nome = nome;
    this->tipo = "Objeto3D";
}

void Objeto3D::adicionarVertice(float x, float y, float z) {
    PontoHomogeneo p = {x, y, z, 1.0f};
    pontos.push_back(p);
    pontosOriginais.push_back(p);
}

void Objeto3D::adicionarFace(const std::vector<int>& indices) {
    faces.push_back(indices);
    for (size_t i = 0; i < indices.size(); ++i) {
        int from = indices[i];
        int to = indices[(i + 1) % indices.size()];
        arestas.emplace_back(from, to);
    }
}

void Objeto3D::desenhar(QPainter &painter, const Matriz &matriz, const Window &window) {
    std::vector<QPointF> pontosProjetados;
    for (const auto& p : pontos) {
        float x = p[0];
        float y = p[1];
        float w = p[3];
        pontosProjetados.emplace_back(x / w, y / w);
    }

    for (const auto& aresta : arestas) {
        int i = aresta.first;
        int j = aresta.second;

        if (i < 0 || j < 0 || i >= static_cast<int>(pontosProjetados.size()) || j >= static_cast<int>(pontosProjetados.size()))
            continue;

        float x1 = pontosProjetados[i].x();
        float y1 = pontosProjetados[i].y();
        float x2 = pontosProjetados[j].x();
        float y2 = pontosProjetados[j].y();

        if (cohenSutherlandClip(x1, y1, x2, y2, window)) {
            Matriz p1(3, 1);
            p1[0][0] = x1;
            p1[1][0] = y1;
            p1[2][0] = 1.0f;

            Matriz p2(3, 1);
            p2[0][0] = x2;
            p2[1][0] = y2;
            p2[2][0] = 1.0f;

            Matriz res1 = matriz * p1;
            Matriz res2 = matriz * p2;

            QPointF ponto1(res1[0][0], res1[1][0]);
            QPointF ponto2(res2[0][0], res2[1][0]);

            painter.drawLine(ponto1, ponto2);
        }
    }
}


void Objeto3D::aplicarTransformacao(const Matriz &matriz) {
    Q_UNUSED(matriz);
}

void Objeto3D::aplicarTransformacao(const Matriz3D &matriz3D) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(4, 0.0f);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                resultado[i] += matriz3D[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

void Objeto3D::transladar(float dx, float dy) {
    for (auto& p : pontos) {
        p[0] += dx;
        p[1] += dy;
    }
    for (auto& p : pontosOriginais) {
        p[0] += dx;
        p[1] += dy;
    }
}

void Objeto3D::escalar(float fator) {
    for (auto& p : pontos) {
        p[0] *= fator;
        p[1] *= fator;
        p[2] *= fator;
    }
    for (auto& p : pontosOriginais) {
        p[0] *= fator;
        p[1] *= fator;
        p[2] *= fator;
    }
}

QPointF Objeto3D::centro() const {
    if (pontos.empty()) return QPointF(0, 0);

    float somaX = 0, somaY = 0;
    for (const auto& p : pontos) {
        somaX += p[0];
        somaY += p[1];
    }
    float n = pontos.size();
    return QPointF(somaX / n, somaY / n);
}

float Objeto3D::getCentroZ() const {
    if (pontosOriginais.empty())
        return 0.0f;

    float soma = 0.0f;
    for (const auto& p : pontosOriginais)
        soma += p[2];

    return soma / pontosOriginais.size();
}

const std::vector<PontoHomogeneo>& Objeto3D::getPontos() const {
    return pontos;
}

void Objeto3D::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}

void Objeto3D::adicionarAresta(int i, int j) {
    arestas.emplace_back(i, j);
}

PontoHomogeneo Objeto3D::calcularCentro() const {
    float somaX = 0, somaY = 0, somaZ = 0;
    int total = pontos.size();

    for (const auto& p : pontos) {
        somaX += p[0];
        somaY += p[1];
        somaZ += p[2];
    }

    return { somaX / total, somaY / total, somaZ / total, 1.0f };
}

float Objeto3D::maiorDistanciaDoCentro() const {
    PontoHomogeneo centro = calcularCentro();
    float maxDist = 0;

    for (const auto& p : pontos) {
        float dx = p[0] - centro[0];
        float dy = p[1] - centro[1];
        float dist = std::sqrt(dx * dx + dy * dy);
        if (dist > maxDist)
            maxDist = dist;
    }

    return maxDist;
}

void Objeto3D::setPontosOriginais(const std::vector<PontoHomogeneo>& novos) {
    pontosOriginais = novos;
}

const std::vector<PontoHomogeneo>& Objeto3D::getPontosOriginais() const {
    return pontosOriginais;
}
