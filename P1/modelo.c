/*	Prácticas de Informática Gráfica

	Grupo C					Curso 2022-23
 	
	Codigo base para la realización de las practicas de IG
	
	Estudiante: 

=======================================================
	G. Arroyo, J.C. Torres 
	Dpto. Lenguajes y Sistemas Informticos
	(Univ. de Granada)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details 
 http://www.gnu.org/copyleft/gpl.html

=======================================================/
modulo modelo.c
    Representación del modelo
    Funciones de dibujo
    Función Idle

*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>		// Libreria de utilidades de OpenGL
#include "practicasIG.h"

/**	void initModel()

Inicializa el modelo y de las variables globales


**/
void
initModel ()
{

}

// Variables
int modo = GL_FILL;

void setModo(int M)
{
  modo = M;
}


class Ejes:Objeto3D 
{ 
public: 
    float longitud = 30;
// Dibuja el objeto
void draw( )
{
  glDisable (GL_LIGHTING);
  glBegin (GL_LINES);
  {
    glColor3f (0, 1, 0);
    glVertex3f (0, 0, 0);
    glVertex3f (0, longitud, 0);

    glColor3f (1, 0, 0);
    glVertex3f (0, 0, 0);
    glVertex3f (longitud, 0, 0);

    glColor3f (0, 0, 1);
    glVertex3f (0, 0, 0);
    glVertex3f (0, 0, longitud);
  }
  glEnd ();
  //glEnable (GL_LIGHTING);

}
} ; 

Ejes ejesCoordenadas;

class Cubo:Objeto3D{
  public:
    float lado;

    Cubo(float lado = 1)
    {
      this->lado = lado;
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

    void draw()
    {
      glPolygonMode(GL_FRONT_AND_BACK,modo);
      glBegin(GL_TRIANGLES);
      for (unsigned int i=0;i<triangulos.size();i++){
        glColor3f(0,0,1);//azul
        glVertex3fv((GLfloat *) &vertices[triangulos[i].a]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].b]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].c]);
      }
      glEnd();
      
    }
};

class Piramide:Objeto3D{
  public:
    float lado, alto;

    Piramide(float lado = 1, float alto = 1)
    {
      this->lado = lado;
      this->alto = alto;

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

    void draw()
    {
      glPolygonMode(GL_FRONT_AND_BACK,modo);
      glBegin(GL_TRIANGLES);
      for (unsigned int i=0;i<triangulos.size();i++){
        glColor3f(1,1,0);//amarillo
        glVertex3fv((GLfloat *) &vertices[triangulos[i].a]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].b]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].c]);
      }
      glEnd();
    }
};

class Octaedro:Objeto3D{
  public:
    float lado, alto;

    Octaedro(float lado = 1, float alto = 1)
    {
      this->lado = lado;
      this->alto = alto;

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

    void draw()
    {
      glPolygonMode(GL_FRONT_AND_BACK,modo);
      glBegin(GL_TRIANGLES);
      for (unsigned int i=0;i<triangulos.size();i++){
        glColor3f(0,1,0);//verde
        glVertex3fv((GLfloat *) &vertices[triangulos[i].a]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].b]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].c]);
      }
      glEnd();
      
    }
};

class Tetraedro:Objeto3D{
  public:
    float lado, alto;

    Tetraedro(float lado = 1, float alto = 1)
    {
      this->lado = lado;
      this->alto = alto;

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

    void draw()
    {
      glPolygonMode(GL_FRONT_AND_BACK,modo);
      glBegin(GL_TRIANGLES);
      for (unsigned int i=0;i<triangulos.size();i++){
        glColor3f(0,1,0);//verde
        glVertex3fv((GLfloat *) &vertices[triangulos[i].a]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].b]);
        glVertex3fv((GLfloat *) &vertices[triangulos[i].c]);
      }
      glEnd();
      
    }
};

/**************************************************************/
// Práctica 1
Cubo cubo(1);
Piramide piramide(1,2);
// Extras
Octaedro octaedro(1,1);
Tetraedro tetraedro(1,2);

/**	void Dibuja( void )

Procedimiento de dibujo del modelo. Es llamado por glut cada vez que se debe redibujar.

**/

void Dibuja (void)
{
  static GLfloat  pos[4] = { 5.0, 5.0, 10.0, 0.0 };	// Posicion de la fuente de luz
 

  float  color[4] = { 0.8, 0.0, 1, 1 };
  float  color2[4] = { 0.0, 0.8, 1, 1 };

  glPushMatrix ();		// Apila la transformacion geometrica actual

  glClearColor (0.0, 0.0, 0.0, 0.0);	// Fija el color de fondo a negro

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Inicializa el buffer de color y el Z-Buffer

  transformacionVisualizacion ();	// Carga transformacion de visualizacion

  glLightfv (GL_LIGHT0, GL_POSITION, pos);	// Declaracion de luz. Colocada aqui esta fija en la escena
  
 

  ejesCoordenadas.draw();			// Dibuja los ejes
  glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

  // Dibuja el modelo (A rellenar en prácticas 1,2 y 3)    

  /**********************************************************/
  // Practica 1
  cubo.draw();
  glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color2);
  glTranslatef(5,0,0);
  piramide.draw();
  // Extra
  glTranslatef(0,0,3);
  octaedro.draw();
  glTranslatef(-5,0,0);
  tetraedro.draw();


  glPopMatrix ();		// Desapila la transformacion geometrica


  glutSwapBuffers ();		// Intercambia el buffer de dibujo y visualizacion
}


/**	void idle()

Procedimiento de fondo. Es llamado por glut cuando no hay eventos pendientes.

**/
void idle (int v)
{

  glutPostRedisplay ();		// Redibuja
  glutTimerFunc (30, idle, 0);	// Vuelve a activarse dentro de 30 ms
}
