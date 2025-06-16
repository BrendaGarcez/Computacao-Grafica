#ifndef OBJETO3D_H
#define OBJETO3D_H

#include "objeto.h"
#include "matriz3d.h"
#include "tipos.h"
#include <QString>
#include <vector>
#include <QPainter>

using Face = std::vector<int>;

class Objeto3D : public Objeto {
public:
    explicit Objeto3D(QString nome);

    void adicionarVertice(float x, float y, float z);
    void adicionarFace(const std::vector<int>& indices);
    void adicionarAresta(int i, int j);

    void desenhar(QPainter &painter, const Matriz &transformacao, const Window& window) override;
    void aplicarTransformacao(const Matriz &matriz) override;
    void aplicarTransformacao(const Matriz3D &matriz3D);

    void transladar(float dx, float dy);
    void escalar(float fator);

    QPointF centro() const override;
    float getCentroZ() const override;

    const std::vector<PontoHomogeneo>& getPontos() const override;
    void setPontos(const std::vector<PontoHomogeneo>& novosPontos) override;

    PontoHomogeneo calcularCentro() const;
    float maiorDistanciaDoCentro() const;

    void setPontosOriginais(const std::vector<PontoHomogeneo>& novos);
    const std::vector<PontoHomogeneo>& getPontosOriginais() const;


private:
    std::vector<PontoHomogeneo> pontos;
    std::vector<PontoHomogeneo> pontosOriginais;
    std::vector<Face> faces;
    std::vector<std::pair<int, int>> arestas;
};

#endif
