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

=======================================================

	 modelo.h
*/

#include "cubo.h"
#include "tetraedro.h"
#include "piramide.h"
#include "octaedro.h"

/**
	Funcion de redibujado. Se ejecuta con los eventos postRedisplay
**/
void Dibuja (void);

/**
	Funcion de fondo
**/
void idle (int v);

/**
	Funcion de inicializacion del modelo y de las variables globales
**/
void initModel ();

/**
	Función que permite cambiar el modo de dibujo
**/
void setModo(int M);

// Práctica 1
Cubo cubo = Cubo(1);
Tetraedro tetraedro = Tetraedro(1,2);
Piramide piramide = Piramide(1,2);
Octaedro octaedro = Octaedro(1,1);
/*
class Objeto3D 
{ 
public: 

virtual void draw( ) = 0; // Dibuja el objeto
} ; 
*/