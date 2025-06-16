#include "matriz3d.h"
#include <cmath>
#include <iomanip>
#include "matriz.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

Matriz3D::Matriz3D(size_t linhas, size_t colunas, float valorInicial) {
    this->resize(linhas, std::vector<float>(colunas, valorInicial));
}

size_t Matriz3D::linhas() const {
    return this->size();
}

size_t Matriz3D::colunas() const {
    return this->empty() ? 0 : this->at(0).size();
}

Matriz3D Matriz3D::operator*(const Matriz3D& outra) const {
    if (colunas() != outra.linhas()) {
        std::cerr << "Erro: Dimensões incompatíveis para multiplicação de matrizes." << std::endl;
        return Matriz3D(0, 0);
    }

    Matriz3D resultado(linhas(), outra.colunas(), 0.0f);
    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < outra.colunas(); ++j)
            for (size_t k = 0; k < colunas(); ++k)
                resultado[i][j] += (*this)[i][k] * outra[k][j];

    return resultado;
}

Matriz3D Matriz3D::transposta() const {
    Matriz3D resultado(colunas(), linhas(), 0.0f);
    for (size_t i = 0; i < linhas(); ++i)
        for (size_t j = 0; j < colunas(); ++j)
            resultado[j][i] = (*this)[i][j];
    return resultado;
}

Matriz3D Matriz3D::identidade(size_t tamanho) {
    Matriz3D I(tamanho, tamanho, 0.0f);
    for (size_t i = 0; i < tamanho; ++i)
        I[i][i] = 1.0f;
    return I;
}

Matriz3D Matriz3D::translacao(float dx, float dy, float dz) {
    Matriz3D T = identidade(4);
    T[0][3] = dx;
    T[1][3] = dy;
    T[2][3] = dz;
    return T;
}

Matriz3D Matriz3D::escala(float sx, float sy, float sz) {
    Matriz3D S = identidade(4);
    S[0][0] = sx;
    S[1][1] = sy;
    S[2][2] = sz;
    return S;
}

Matriz3D Matriz3D::rotacaoX(float anguloGraus, float px, float py, float pz) {
    float rad = grauParaRad(anguloGraus);
    float c = std::cos(rad);
    float s = std::sin(rad);

    Matriz3D T1 = translacao(-px, -py, -pz);
    Matriz3D R = identidade(4);
    R[1][1] = c; R[1][2] = -s;
    R[2][1] = s; R[2][2] = c;
    Matriz3D T2 = translacao(px, py, pz);

    return T2 * R * T1;
}

Matriz3D Matriz3D::rotacaoY(float anguloGraus, float px, float py, float pz) {
    float rad = grauParaRad(anguloGraus);
    float c = std::cos(rad);
    float s = std::sin(rad);

    Matriz3D T1 = translacao(-px, -py, -pz);
    Matriz3D R = identidade(4);
    R[0][0] = c; R[0][2] = s;
    R[2][0] = -s; R[2][2] = c;
    Matriz3D T2 = translacao(px, py, pz);

    return T2 * R * T1;
}

Matriz3D Matriz3D::rotacaoZ(float anguloGraus, float px, float py, float pz) {
    float rad = grauParaRad(anguloGraus);
    float c = std::cos(rad);
    float s = std::sin(rad);

    Matriz3D T1 = translacao(-px, -py, -pz);
    Matriz3D R = identidade(4);
    R[0][0] = c; R[0][1] = -s;
    R[1][0] = s; R[1][1] = c;
    Matriz3D T2 = translacao(px, py, pz);

    return T2 * R * T1;
}

std::ostream& operator<<(std::ostream& os, const Matriz3D& m) {
    for (size_t i = 0; i < m.linhas(); ++i) {
        for (size_t j = 0; j < m.colunas(); ++j) {
            os << std::fixed << std::setprecision(4) << m[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}
