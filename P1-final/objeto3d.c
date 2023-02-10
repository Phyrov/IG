#include "objeto3d.h"

void Objeto3D::draw_point()
{
    float color[4] = {0.5,1.0,0.5,1};
    //glShadeModel(GL_FLAT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glBegin(GL_TRIANGLES);

    for(int i=0; i<triangulos.size(); i++){
        glVertex3f(vertices[triangulos[i].v0].x, vertices[triangulos[i].v0].y, vertices[triangulos[i].v0].z);
        glVertex3f(vertices[triangulos[i].v1].x, vertices[triangulos[i].v1].y, vertices[triangulos[i].v1].z);
        glVertex3f(vertices[triangulos[i].v2].x, vertices[triangulos[i].v2].y, vertices[triangulos[i].v2].z);
    }

    glEnd();
}

void Objeto3D::draw_line()
{
    float color[4] = {0.5,1.0,0.5,1};
    //glShadeModel(GL_FLAT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    for(int i=0; i<triangulos.size(); i++){
        glVertex3f(vertices[triangulos[i].v0].x, vertices[triangulos[i].v0].y, vertices[triangulos[i].v0].z);
        glVertex3f(vertices[triangulos[i].v1].x, vertices[triangulos[i].v1].y, vertices[triangulos[i].v1].z);
        glVertex3f(vertices[triangulos[i].v2].x, vertices[triangulos[i].v2].y, vertices[triangulos[i].v2].z);
    }

    glEnd();
}

void Objeto3D::draw_fill()
{
    float color[4] = {0.5,1.0,0.5,1};
    //glShadeModel(GL_FLAT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);

    for(int i=0; i<triangulos.size(); i++){
        glVertex3f(vertices[triangulos[i].v0].x, vertices[triangulos[i].v0].y, vertices[triangulos[i].v0].z);
        glVertex3f(vertices[triangulos[i].v1].x, vertices[triangulos[i].v1].y, vertices[triangulos[i].v1].z);
        glVertex3f(vertices[triangulos[i].v2].x, vertices[triangulos[i].v2].y, vertices[triangulos[i].v2].z);
    }

    glEnd();
}