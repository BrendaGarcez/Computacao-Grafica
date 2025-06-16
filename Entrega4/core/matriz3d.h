#ifndef MATRIZ3D_H
#define MATRIZ3D_H

#include <vector>
#include <iostream>

class Matriz3D : public std::vector<std::vector<float>> {
public:
    Matriz3D(size_t linhas = 4, size_t colunas = 4, float valorInicial = 0.0f);

    size_t linhas() const;
    size_t colunas() const;

    Matriz3D transposta() const;
    Matriz3D operator*(const Matriz3D& outra) const;

    static Matriz3D identidade(size_t tamanho);
    static Matriz3D translacao(float dx, float dy, float dz);
    static Matriz3D escala(float sx, float sy, float sz);
    static Matriz3D rotacaoX(float anguloGraus, float px = 0.0f, float py = 0.0f, float pz = 0.0f);
    static Matriz3D rotacaoY(float anguloGraus, float px = 0.0f, float py = 0.0f, float pz = 0.0f);
    static Matriz3D rotacaoZ(float anguloGraus, float px = 0.0f, float py = 0.0f, float pz = 0.0f);
};

std::ostream& operator<<(std::ostream& os, const Matriz3D& m);

#endif
