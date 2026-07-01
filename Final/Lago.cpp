#include "Lago.h"
#include <GL/glut.h>

Lago::Lago()
{
	x = 0.0f;
	y = -39.4f;      // ligeramente sobre el terreno
	z = -235.0f;     // conectado al final del río
	
	nivelAgua = 0.0f;
}

void Lago::dibujar()
{
	glPushMatrix();
	
	glTranslatef(x,y,z);
	
	GLfloat difusa[]   ={0.0f,0.45f,1.0f,1.0f};
	GLfloat ambiente[] ={0.0f,0.25f,0.8f,1.0f};
	GLfloat specular[] ={0.9f,0.9f,1.0f,1.0f};
	GLfloat brillo[]   ={90.0f};
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,difusa);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambiente);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,brillo);
	
	glColor3f(0.0f,0.5f,1.0f);
	
	//-------------------------
	// Superficie
	//-------------------------
	
	glBegin(GL_POLYGON);
	
	glNormal3f(0,1,0);
	
	glVertex3f(  0,  nivelAgua,  95);
	glVertex3f( 50,  nivelAgua,  85);
	glVertex3f( 95,  nivelAgua,  45);
	glVertex3f(105,  nivelAgua, -15);
	glVertex3f( 90,  nivelAgua, -70);
	glVertex3f( 45,  nivelAgua,-100);
	glVertex3f(-20,  nivelAgua, -90);
	glVertex3f(-70,  nivelAgua, -75);
	glVertex3f(-95,  nivelAgua, -25);
	glVertex3f(-90,  nivelAgua,  35);
	glVertex3f(-60,  nivelAgua,  80);
	glVertex3f(-15,  nivelAgua, 100);
	
	glEnd();
	
	//-------------------------
	// Bordes
	//-------------------------
	
	glBegin(GL_TRIANGLE_FAN);
	
	glNormal3f(0,-1,0);
	
	glVertex3f(0,-8,0);
	
	glVertex3f(  0, nivelAgua,  55);
	glVertex3f( 25, nivelAgua,  45);
	glVertex3f( 50, nivelAgua,  20);
	glVertex3f( 55, nivelAgua, -10);
	glVertex3f( 45, nivelAgua, -35);
	glVertex3f( 20, nivelAgua, -55);
	glVertex3f(-10, nivelAgua, -50);
	glVertex3f(-35, nivelAgua, -40);
	glVertex3f(-55, nivelAgua, -15);
	glVertex3f(-50, nivelAgua,  15);
	glVertex3f(-35, nivelAgua,  40);
	glVertex3f(-10, nivelAgua,  52);
	glVertex3f(  0, nivelAgua,  55);
	
	glEnd();
	
	glPopMatrix();
}
