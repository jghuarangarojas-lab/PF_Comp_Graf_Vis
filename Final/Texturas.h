#ifndef TEXTURAS_H
#define TEXTURAS_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

struct Textura
{
	GLubyte* dibujo;
	GLuint bpp;
	GLuint ancho;
	GLuint largo;
	GLuint ID;
	
};


class Texturas
{
private:
	
	Textura cielo;
	Textura pasto;
	Textura agua;
	Textura roca;
	Textura arena;
	
	int cargarTGA(const char* nombre, Textura* imagen);
	
public:
	
	Texturas();
	
	void cargarTexturas();
	
	GLuint getCielo();
	GLuint getPasto();
	GLuint getAgua();
	GLuint getRoca();
	GLuint getArena();
};

#endif
