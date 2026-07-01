#ifndef RIO_H
#define RIO_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Rio
{
private:
	float x;
	float y;
	float z;
	
	float ancho;
	float nivelAgua;
	
	struct PuntoRio
	{
		float izqX;
		float derX;
		float z;
	};
	
	static const int NUM_PUNTOS = 8;
	
	PuntoRio puntos[NUM_PUNTOS];
public:
	Rio();
	void dibujar(GLuint textura);
};

#endif
