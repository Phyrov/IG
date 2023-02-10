#include "piramide.h"

Piramide::Piramide(float lado, float alto)
{
    vertices.resize(5);
    vertices[0] = Vertice(-lado, -lado, lado);
    vertices[1] = Vertice(lado, -lado, lado);
    vertices[2] = Vertice(lado, -lado, -lado);
    vertices[3] = Vertice(-lado, -lado, -lado);
    vertices[4] = Vertice(0, alto, 0);

    triangulos.resize(6);

    // Cara delantera
    triangulos[0] = Triangulo(0, 1, 4);
    // Cara derecha
    triangulos[1] = Triangulo(1, 2, 4);
    // Cara trasera
    triangulos[2] = Triangulo(2, 3, 4);
    // Cara izquierda
    triangulos[3] = Triangulo(3, 0, 4);
    // Cara abajo
    triangulos[4] = Triangulo(0, 2, 1);
    triangulos[5] = Triangulo(0, 3, 2);
}