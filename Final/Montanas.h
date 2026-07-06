#ifndef MONTANAS_H
#define MONTANAS_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class Montanas
{
private:
	
	void dibujarMontana(float x, float z, float base, float altura, GLuint textura);
	
public:
	
	Montanas();
	void dibujar(GLuint texturaRoca);
};
#endif
