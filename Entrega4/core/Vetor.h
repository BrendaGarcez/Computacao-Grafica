#ifndef VETOR_H
#define VETOR_H

#include <cmath> 
#include <iostream> 

class Vetor {
public:
    float x, y, z;

    Vetor();

    Vetor(float x_val, float y_val, float z_val);


    float magnitude() const;


    Vetor normalizar() const;

    
    float produto_escalar(const Vetor& outro) const;

    Vetor produto_vetorial(const Vetor& outro) const;

    Vetor operator+(const Vetor& outro) const;
    Vetor operator-(const Vetor& outro) const;

    Vetor operator*(float escalar) const;

    Vetor operator/(float escalar) const;

    friend std::ostream& operator<<(std::ostream& os, const Vetor& v);
};

#endif // VETOR_H