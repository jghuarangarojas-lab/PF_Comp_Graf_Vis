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
#include <cmath>

Terreno::Terreno()
{
	tamano = 720.0f;
	divisiones = 5;
	altura = -40.0f;
}


void Terreno::dibujar(GLuint textura)
{
	float paso=tamano/divisiones;
	float repeticion=5.0f;
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textura);
	
	glColor3f(1,1,1);
	
	glBegin(GL_QUADS);
	
	for(int i=0;i<divisiones;i++)
	{
		for(int j=0;j<divisiones;j++)
		{
			float x=-tamano/2+i*paso;
			float z=-tamano/2+j*paso;
			
			float h1=obtenerAltura(x,z);
			float h2=obtenerAltura(x+paso,z);
			float h3=obtenerAltura(x+paso,z+paso);
			float h4=obtenerAltura(x,z+paso);
			
			float u0=repeticion*i/divisiones;
			float v0=repeticion*j/divisiones;
			
			float u1=repeticion*(i+1)/divisiones;
			float v1=repeticion*(j+1)/divisiones;
			
			glNormal3f(0,1,0);
			
			glTexCoord2f(u0,v0);
			glVertex3f(x,h1,z);
			
			glTexCoord2f(u1,v0);
			glVertex3f(x+paso,h2,z);
			
			glTexCoord2f(u1,v1);
			glVertex3f(x+paso,h3,z+paso);
			
			glTexCoord2f(u0,v1);
			glVertex3f(x,h4,z+paso);
		}
	}
	
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
}

float Terreno::obtenerAltura(float x,float z)
{
	return altura
		+ 2.5f * sin(x * 0.03f)
		+ 2.0f * cos(z * 0.025f)
		+ 1.2f * sin((x + z) * 0.02f);
}
