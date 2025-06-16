#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <cstddef>
#include <cmath>

inline float grauParaRad(float grau) {
    return grau * M_PI / 180.0f;
}

using namespace std;

using PontoHomogeneo = std::vector<float>;

class Matriz : public vector<vector<float>> {
public:
    Matriz(size_t linhas, size_t colunas, float valorInicial = 0.0f);

    size_t linhas() const;
    size_t colunas() const;

    Matriz transposta() const;
    Matriz operator*(const Matriz& outra) const;

    static Matriz identidade(size_t tamanho);
    static Matriz translacao(float dx, float dy);
    static Matriz escala(float sx, float sy);
    static Matriz rotacao(float anguloGraus, float px = 0.0f, float py = 0.0f);
};

#endif
