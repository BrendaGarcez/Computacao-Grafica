#include "reta.h"
#include "coordenadas.h"
#include <QPainter>

bool cohenSutherlandClip(float &x1, float &y1, float &x2, float &y2, const Window& window);

Reta::Reta(QString nome, float x1, float y1, float x2, float y2) {
    this->nome = nome;
    this->tipo = "Reta";

    pontos.push_back({x1, y1, 1.0f});
    pontos.push_back({x2, y2, 1.0f});
    pontosOriginais = pontos;
}

void Reta::desenhar(QPainter &painter, const Matriz &transformacao, const Window &window) {
    float x1 = pontos[0][0];
    float y1 = pontos[0][1];
    float x2 = pontos[1][0];
    float y2 = pontos[1][1];

    if (cohenSutherlandClip(x1, y1, x2, y2, window)) {
        Matriz p1(3, 1);
        p1[0][0] = x1;
        p1[1][0] = y1;
        p1[2][0] = 1.0f;

        Matriz p2(3, 1);
        p2[0][0] = x2;
        p2[1][0] = y2;
        p2[2][0] = 1.0f;

        Matriz resultado1 = transformacao * p1;
        Matriz resultado2 = transformacao * p2;

        QPen pen(Qt::blue);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawLine(QPointF(resultado1[0][0], resultado1[1][0]),
                         QPointF(resultado2[0][0], resultado2[1][0]));
    }
}

void Reta::aplicarTransformacao(const Matriz &matriz) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Reta::centro() const {
    float x = (pontos[0][0] + pontos[1][0]) / 2.0f;
    float y = (pontos[0][1] + pontos[1][1]) / 2.0f;
    return QPointF(x, y);
}

const std::vector<PontoHomogeneo>& Reta::getPontos() const {
    return pontos;
}

void Reta::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}
