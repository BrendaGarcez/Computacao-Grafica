#ifndef OBJETO_H
#define OBJETO_H

#include <QString>
#include <vector>
#include <QPointF>
#include <QPainter>

#include "matriz.h"
#include "coordenadas.h"

class Objeto {
public:
    QString nome;
    QString tipo;
    std::vector<PontoHomogeneo> pontos;
    std::vector<PontoHomogeneo> pontosOriginais;

    virtual ~Objeto() {}

    virtual void desenhar(QPainter &painter, const Matriz &transformacao, const Window& window) = 0;
    virtual void aplicarTransformacao(const Matriz &matriz) = 0;
    virtual QPointF centro() const = 0;
    virtual const std::vector<PontoHomogeneo>& getPontos() const = 0;
    virtual void setPontos(const std::vector<PontoHomogeneo>& novosPontos) = 0;
    virtual float getCentroZ() const { return 0.0f; }

};

#endif
