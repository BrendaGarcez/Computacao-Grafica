#include "matriz.h"
#include <cmath>
#include <QPointF>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

float meuSeno(float x) {
    return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f;
}

float meuCosseno(float x) {
    return 1.0f - (x * x) / 2.0f + (x * x * x * x) / 24.0f;
}

Matriz::Matriz(size_t linhas, size_t colunas, float valorInicial) {
    this->resize(linhas, vector<float>(colunas, valorInicial));
}

size_t Matriz::linhas() const {
    return this->size();
}

size_t Matriz::colunas() const {
    return this->empty() ? 0 : this->at(0).size();
}

Matriz Matriz::operator*(const Matriz& outra) const {
    Matriz resultado(linhas(), outra.colunas(), 0.0f);

    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < outra.colunas(); ++j)
            for (size_t k = 0; k < colunas(); ++k)
                resultado[i][j] += (*this)[i][k] * outra[k][j];

    return resultado;
}

Matriz Matriz::transposta() const {
    Matriz resultado(colunas(), linhas(), 0.0f);
    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < colunas(); ++j)
            resultado[j][i] = (*this)[i][j];
    return resultado;
}

Matriz Matriz::identidade(size_t tamanho) {
    Matriz I(tamanho, tamanho, 0.0f);
    for (size_t i = 0; i < tamanho; ++i)
        I[i][i] = 1.0f;
    return I;
}

Matriz Matriz::translacao(float dx, float dy) {
    Matriz T = identidade(3);
    T[0][2] = dx;
    T[1][2] = dy;
    return T;
}

Matriz Matriz::escala(float sx, float sy) {
    Matriz S = identidade(3);
    S[0][0] = sx;
    S[1][1] = sy;
    return S;
}

Matriz Matriz::rotacao(float anguloGraus, float px, float py) {
    float rad = grauParaRad(anguloGraus);
    float c = cos(rad);   //meuCosseno(rad);
    float s = sin(rad);   //meuSeno(rad);

    Matriz T1 = Matriz::translacao(-px, -py);
    Matriz R = Matriz::identidade(3);
    R[0][0] = c;
    R[0][1] = -s;
    R[1][0] = s;
    R[1][1] = c;

    Matriz T2 = Matriz::translacao(px, py);
    return T2 * R * T1;
}

QPointF operator*(const Matriz& m, const QPointF& p) {
    float x = p.x();
    float y = p.y();
    std::vector<float> ponto = {x, y, 1.0f};

    std::vector<float> resultado(3, 0.0f);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            resultado[i] += m[i][j] * ponto[j];

    return QPointF(resultado[0], resultado[1]);
}



