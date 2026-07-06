#include "Rio.h"
#include <GL/glut.h>

Rio::Rio()
{
	x = 0.0f;
	y = -34.5f;      // Un poco sobre el terreno para evitar parpadeos (z-fighting)
	z = 0.0f;
	desplazamientoTextura = 0.0f;
	ancho = 12.0f;
	nivelAgua = 0.0f;
	puntos[0] = {-18,18,190};
	puntos[1] = {-24,18,145};
	puntos[2] = {-12,28,95};
	puntos[3] = {-30,20,40};
	puntos[4] = {-40,30,-40};
	puntos[5] = {-55,40,-90};
	puntos[6] = {-75,60,-140};
	puntos[7] = {-95,90,-185};
}

void Rio::dibujar(GLuint textura)
{
	glPushMatrix();
	
	glTranslatef(x, y, z);
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D,textura);
	// Color del agua
	//glColor3f(0.0f, 0.45f, 1.0f);
	
	GLfloat mat_diffuse[]  = {0.0f, 0.45f, 1.0f, 1.0f};
	GLfloat mat_ambient[]  = {0.0f, 0.25f, 0.8f, 1.0f};
	GLfloat mat_specular[] = {0.8f, 0.8f, 1.0f, 1.0f};
	GLfloat mat_shininess[]= {80.0f};
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	
	glBegin(GL_QUAD_STRIP);
	
	for(int i=0;i<NUM_PUNTOS;i++)
	{
		float v = (float)i*0.1f - desplazamientoTextura;
		
		glTexCoord2f(0.0f,v);
		glVertex3f(puntos[i].izqX,nivelAgua,puntos[i].z);
		
		glTexCoord2f(1.0f,v);
		glVertex3f(puntos[i].derX,nivelAgua,puntos[i].z);
	}
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Rio::actualizar()
{
	desplazamientoTextura += 0.001f;
	
	if(desplazamientoTextura > 1.0f)
		desplazamientoTextura -= 1.0f;
}
