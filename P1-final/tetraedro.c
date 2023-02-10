#include "tetraedro.h"

Tetraedro::Tetraedro(float lado, float alto)
{
    vertices.resize(4);
    vertices[0] = Vertice(-lado, -lado, lado);
    vertices[1] = Vertice(lado, -lado, lado);
    vertices[2] = Vertice(0, -lado, -lado);
    vertices[3] = Vertice(0, alto, 0);

    triangulos.resize(6);

    // Cara delantera
    triangulos[0] = Triangulo(0, 1, 3);
    // Cara derecha
    triangulos[1] = Triangulo(1, 2, 3);
    // Cara izquierda
    triangulos[2] = Triangulo(2, 0, 3);
    // Cara abajo
    triangulos[3] = Triangulo(0, 2, 1);
}