#ifndef TERRENO_H
#define TERRENO_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Terreno
{
private:
	
private:
	
	float tamano;
	float altura;
	
	int divisiones;
	
	float obtenerAltura(float x,float z);

public:
	
	Terreno();
	void dibujar(GLuint textura);
};

#endif
