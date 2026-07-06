#ifndef LAGO_H
#define LAGO_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
class Lago
{
private:
	
	float x;
	float y;
	float z;
	
	float nivelAgua;
	
public:
	
	Lago();
	void dibujar(GLuint textura);
	
};

#endif
