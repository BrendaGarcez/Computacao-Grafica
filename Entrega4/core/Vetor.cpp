#include "Vetor.h"

Vetor::Vetor() : x(0.0f), y(0.0f), z(0.0f) {}

Vetor::Vetor(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {}

float Vetor::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vetor Vetor::normalizar() const {
    float mag = magnitude();
    if (mag > 1e-6) { 
        return Vetor(x / mag, y / mag, z / mag);
    }
    return Vetor();
}

float Vetor::produto_escalar(const Vetor& outro) const {
    return (x * outro.x) + (y * outro.y) + (z * outro.z);
}

Vetor Vetor::produto_vetorial(const Vetor& outro) const {
    return Vetor(
        y * outro.z - z * outro.y,
        z * outro.x - x * outro.z,
        x * outro.y - y * outro.x
    );
}

Vetor Vetor::operator+(const Vetor& outro) const {
    return Vetor(x + outro.x, y + outro.y, z + outro.z);
}

Vetor Vetor::operator-(const Vetor& outro) const {
    return Vetor(x - outro.x, y - outro.y, z - outro.z);
}

Vetor Vetor::operator*(float escalar) const {
    return Vetor(x * escalar, y * escalar, z * escalar);
}

Vetor Vetor::operator/(float escalar) const {
    if (std::abs(escalar) > 1e-6) { 
        return Vetor(x / escalar, y / escalar, z / escalar);
    }
    std::cerr << "Aviso: Divisao de vetor por escalar proximo de zero." << std::endl;
    return Vetor();
}

std::ostream& operator<<(std::ostream& os, const Vetor& v) {
    os << "Vetor(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}