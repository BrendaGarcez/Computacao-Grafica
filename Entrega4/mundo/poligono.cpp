#include "poligono.h"
#include "coordenadas.h"
#include "cohen_sutherland.h"

Poligono::Poligono(QString nome, std::vector<PontoHomogeneo> pontos) {
    this->nome = nome;
    this->tipo = "Poligono";
    this->pontos = pontos;
    this->pontosOriginais = pontos;
}

void Poligono::desenhar(QPainter &painter, const Matriz &transformacao, const Window& window) {
    QPen pen(Qt::darkGreen);
    pen.setWidth(2);
    painter.setPen(pen);

    int n = pontos.size();
    for (int i = 0; i < n; ++i) {
        float x1 = pontos[i][0];
        float y1 = pontos[i][1];
        float x2 = pontos[(i + 1) % n][0];
        float y2 = pontos[(i + 1) % n][1];

        if (cohenSutherlandClip(x1, y1, x2, y2, window)) {
            Matriz p1(3, 1);
            p1[0][0] = x1; p1[1][0] = y1; p1[2][0] = 1.0f;

            Matriz p2(3, 1);
            p2[0][0] = x2; p2[1][0] = y2; p2[2][0] = 1.0f;

            Matriz resultado1 = transformacao * p1;
            Matriz resultado2 = transformacao * p2;

            painter.drawLine(QPointF(resultado1[0][0], resultado1[1][0]),
                             QPointF(resultado2[0][0], resultado2[1][0]));
        }
    }
}

void Poligono::aplicarTransformacao(const Matriz &matriz) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Poligono::centro() const {
    float somaX = 0, somaY = 0;
    for (const auto& p : pontos) {
        somaX += p[0];
        somaY += p[1];
    }
    float n = pontos.size();
    return QPointF(somaX / n, somaY / n);
}

const std::vector<PontoHomogeneo>& Poligono::getPontos() const {
    return pontos;
}

void Poligono::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}
