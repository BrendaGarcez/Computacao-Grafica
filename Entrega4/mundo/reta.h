#pragma once
#include "coordenadas.h"
#include "objeto.h"
#include "matriz.h"
#include <QPainter>

class Reta : public Objeto {
public:
    Reta(QString nome, float x1, float y1, float x2, float y2);

    void desenhar(QPainter &painter, const Matriz &transformacao, const Window &window) override;

    void aplicarTransformacao(const Matriz &matriz) override;
    QPointF centro() const override;
    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;

private:
    std::vector<PontoHomogeneo> pontos;
    std::vector<PontoHomogeneo> pontosOriginais;
};
