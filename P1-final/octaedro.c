#include "octaedro.h"
    
Octaedro::Octaedro(float lado, float alto){
    vertices.resize(6);
    vertices[0] = Vertice(-lado, 0, lado);
    vertices[1] = Vertice(lado, 0, lado);
    vertices[2] = Vertice(lado, 0, -lado);
    vertices[3] = Vertice(-lado, 0, -lado);
    vertices[4] = Vertice(0, alto, 0);
    vertices[5] = Vertice(0, -alto, 0);

    triangulos.resize(8);
    // Cara delantera
    triangulos[0] = Triangulo(0, 1, 4);
    triangulos[1] = Triangulo(0, 5, 1);
    // Cara derecha
    triangulos[2] = Triangulo(1, 2, 4);
    triangulos[3] = Triangulo(1, 5, 2);
    // Cara trasera
    triangulos[4] = Triangulo(2, 3, 4);
    triangulos[5] = Triangulo(2, 5, 3);
    // Cara izquierda
    triangulos[6] = Triangulo(3, 0, 4);
    triangulos[7] = Triangulo(3, 5, 0);
}