#ifndef PONTO_H
#define PONTO_H

#include "objeto.h"
#include "tipos.h"
#include "matriz.h"
#include <QPainter>

class Ponto : public Objeto {
public:
    Ponto(QString nome, float x, float y);

    void desenhar(QPainter &painter, const Matriz &transformacao, const Window &window) override;
    void aplicarTransformacao(const Matriz &matriz) override;
    QPointF centro() const override;
    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;

private:
    std::vector<PontoHomogeneo> pontos;
};

#endif


