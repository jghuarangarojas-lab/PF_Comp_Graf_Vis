#include "Lago.h"
#include <GL/glut.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Lago::Lago()
{
	x = 0.0f;
	y = -34.4f;      // ligeramente sobre el terreno
	z = -235.0f;     // conectado al final del río
	
	nivelAgua = 0.0f;
}

void Lago::dibujar(GLuint textura)
{
	glPushMatrix();
	
	glTranslatef(x,y,z);
	
	// Aumentar ligeramente el tamaño del lago
	glScalef(1.25f,1.0f,1.25f);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textura);
	
	GLfloat difusa[]   ={0.0f,0.45f,1.0f,1.0f};
	GLfloat ambiente[] ={0.0f,0.25f,0.8f,1.0f};
	GLfloat specular[] ={0.9f,0.9f,1.0f,1.0f};
	GLfloat brillo[]   ={90.0f};
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,difusa);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambiente);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,brillo);
	
	glColor3f(1,1,1);
	
	//-------------------------
	// Superficie
	//-------------------------
	
	glBegin(GL_POLYGON);
	
	glNormal3f(0,1,0);
	
	glTexCoord2f(0.50f,1.00f); glVertex3f(  0,nivelAgua, 95);
	glTexCoord2f(0.75f,0.95f); glVertex3f( 50,nivelAgua, 85);
	glTexCoord2f(0.95f,0.75f); glVertex3f( 95,nivelAgua, 45);
	glTexCoord2f(1.00f,0.45f); glVertex3f(105,nivelAgua,-15);
	glTexCoord2f(0.90f,0.15f); glVertex3f( 90,nivelAgua,-70);
	glTexCoord2f(0.70f,0.00f); glVertex3f( 45,nivelAgua,-100);
	glTexCoord2f(0.40f,0.05f); glVertex3f(-20,nivelAgua,-90);
	glTexCoord2f(0.15f,0.15f); glVertex3f(-70,nivelAgua,-75);
	glTexCoord2f(0.00f,0.40f); glVertex3f(-95,nivelAgua,-25);
	glTexCoord2f(0.05f,0.70f); glVertex3f(-90,nivelAgua, 35);
	glTexCoord2f(0.20f,0.95f); glVertex3f(-60,nivelAgua, 80);
	glTexCoord2f(0.45f,1.00f); glVertex3f(-15,nivelAgua,100);
	
	glEnd();
	
	//-------------------------
	// Fondo
	//-------------------------
	
	glBegin(GL_TRIANGLE_FAN);
	
	glNormal3f(0,-1,0);
	
	glTexCoord2f(0.5f,0.5f);
	glVertex3f(0,-8,0);
	
	glTexCoord2f(0.50f,1.00f); glVertex3f(  0,nivelAgua, 55);
	glTexCoord2f(0.70f,0.90f); glVertex3f( 25,nivelAgua, 45);
	glTexCoord2f(0.90f,0.70f); glVertex3f( 50,nivelAgua, 20);
	glTexCoord2f(1.00f,0.45f); glVertex3f( 55,nivelAgua,-10);
	glTexCoord2f(0.85f,0.20f); glVertex3f( 45,nivelAgua,-35);
	glTexCoord2f(0.65f,0.05f); glVertex3f( 20,nivelAgua,-55);
	glTexCoord2f(0.45f,0.05f); glVertex3f(-10,nivelAgua,-50);
	glTexCoord2f(0.20f,0.15f); glVertex3f(-35,nivelAgua,-40);
	glTexCoord2f(0.05f,0.40f); glVertex3f(-55,nivelAgua,-15);
	glTexCoord2f(0.10f,0.65f); glVertex3f(-50,nivelAgua, 15);
	glTexCoord2f(0.25f,0.90f); glVertex3f(-35,nivelAgua, 40);
	glTexCoord2f(0.45f,0.98f); glVertex3f(-10,nivelAgua, 52);
	glTexCoord2f(0.50f,1.00f); glVertex3f(  0,nivelAgua, 55);
	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,0);
	glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}
