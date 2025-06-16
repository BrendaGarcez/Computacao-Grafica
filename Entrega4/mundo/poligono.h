#ifndef POLIGONO_H
#define POLIGONO_H

#pragma once
#include "objeto.h"
#include "matriz.h"
#include "coordenadas.h"
#include <QPainter>

class Poligono : public Objeto {
public:
    Poligono(QString nome, std::vector<PontoHomogeneo> pontos);

    void desenhar(QPainter &painter, const Matriz &transformacao, const Window& window) override;

    void aplicarTransformacao(const Matriz &matriz) override;
    QPointF centro() const override;
    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;
};

#endif
