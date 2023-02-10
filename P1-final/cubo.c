#include "cubo.h"

Cubo::Cubo(float lado)
{
    
    vertices.resize(8);
    vertices[0] = Vertice(-lado, -lado, lado);
    vertices[1] = Vertice(lado, -lado, lado);
    vertices[2] = Vertice(lado, lado, lado);
    vertices[3] = Vertice(-lado, lado, lado);
    vertices[4] = Vertice(lado, -lado, -lado);
    vertices[5] = Vertice(lado, lado, -lado);
    vertices[6] = Vertice(-lado, lado, -lado);
    vertices[7] = Vertice(-lado, -lado, -lado);

    triangulos.resize(12);
    // Cara delantera
    triangulos[0] = Triangulo(0, 1, 3);
    triangulos[1] = Triangulo(1, 2, 3);
    // Cara derecha
    triangulos[2] = Triangulo(1, 5, 2);
    triangulos[3] = Triangulo(1, 4, 5);
    /// Cara superior
    triangulos[4] = Triangulo(3, 2, 5);
    triangulos[5] = Triangulo(3, 5, 6);
    // Cara izquierda
    triangulos[6] = Triangulo(0, 3, 6);
    triangulos[7] = Triangulo(0, 6, 7);
    // Cara abajo
    triangulos[8] = Triangulo(0, 4, 1);
    triangulos[9] = Triangulo(0, 7, 4);
    // Cara trasera
    triangulos[10] = Triangulo(6, 5, 4);
    triangulos[11] = Triangulo(6, 4, 7);
}