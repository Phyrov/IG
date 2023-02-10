
#ifndef OBJETO3D_H
#define OBJETO3D_H

#include "triangulo.h"
#include "vertice.h"
#include <vector>
#include <GL/gl.h>

class Objeto3D
{
    public: 
        std::vector<Vertice> vertices;
        std::vector<Triangulo> triangulos;
        void draw_point();
        void draw_line();
        void draw_fill();

};

#endif