#include "ponto.h"

Ponto::Ponto(QString nome, float x, float y) {
    this->nome = nome;
    this->tipo = "Ponto";

    PontoHomogeneo p = {x, y, 1.0f};
    pontos.push_back(p);
    pontosOriginais = pontos;
}

void Ponto::desenhar(QPainter &painter, const Matriz& transformacao, const Window &window) {
    if (pontos.empty()) return;

    PontoHomogeneo p = pontos[0];

    Matriz ponto(3, 1);
    ponto[0][0] = p[0];
    ponto[1][0] = p[1];
    ponto[2][0] = 1.0f;

    Matriz resultado = transformacao * ponto;

    painter.drawPoint(QPointF(resultado[0][0], resultado[1][0]));
}

void Ponto::aplicarTransformacao(const Matriz &matriz) {
    pontos.clear();
    for (const auto& p : pontosOriginais) {
        PontoHomogeneo resultado(3, 0.0f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                resultado[i] += matriz[i][j] * p[j];
        pontos.push_back(resultado);
    }
}

QPointF Ponto::centro() const {
    return QPointF(pontos[0][0], pontos[0][1]);
}

const std::vector<PontoHomogeneo>& Ponto::getPontos() const {
    return pontos;
}

void Ponto::setPontos(const std::vector<PontoHomogeneo>& novosPontos) {
    pontos = novosPontos;
}

