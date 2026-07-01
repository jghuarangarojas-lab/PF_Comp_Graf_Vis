#include "Terreno.h"
#include <GL/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Terreno::Terreno()
{
	tamano = 500.0f;
	divisiones = 30;
	altura = -40.0f;
}


void Terreno::dibujar(GLuint textura)
{
	float paso = tamano/divisiones;
	float repeticion = 30.0f;
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D,textura);
	
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	for(int i=0;i<divisiones;i++)
	{
		for(int j=0;j<divisiones;j++)
		{
			float x=-tamano/2+i*paso;
			float z=-tamano/2+j*paso;

			float u0 = repeticion * i / divisiones;
			float v0 = repeticion * j / divisiones;
			
			float u1 = repeticion * (i + 1) / divisiones;
			float v1 = repeticion * (j + 1) / divisiones;
			
			glTexCoord2f(u0, v0);
			glVertex3f(x, altura, z);
			
			glTexCoord2f(u1, v0);
			glVertex3f(x+paso, altura, z);
			
			glTexCoord2f(u1, v1);
			glVertex3f(x+paso, altura, z+paso);
			
			glTexCoord2f(u0, v1);
			glVertex3f(x, altura, z+paso);
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

float obtenerAltura(float x,float z){
	return x;
}
