#include "Nube.h"
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
Nube::Nube()
{
	//Nubes
	for(int i=0;i<NUM_NUBES;i++)
	{
		x[i] = -120 + rand()%240;
		
		y[i] = 100 + rand()%25;
		
		z[i] = 120 + rand()%70;
		
		radio[i]=20.0f;
	}
	for(int i=0; i<NUM_NUBES; i++)
	{
		velocidadNube[i] = 0.02f + (rand() % 5) * 0.01f;
	}
	velocidadNueva = 0.03f;	
	
	radioNueva = 0.0f;
	xNueva = 0.0f;
	yNueva = 90.0f;
	zNueva = -230.0f;
	
	nubeActiva = false;
	vaporAcumulado = 0;
}

void Nube::dibujarNube(float r)
{
	// Esfera izquierda
	glPushMatrix();
	glutSolidSphere(r,30,30);
	glPopMatrix();
	
	// Esfera central
	glPushMatrix();
	glTranslatef(25.0f,5.0f,0.0f);
	glutSolidSphere(r+6,30,30);
	glPopMatrix();
	
	// Esfera derecha
	glPushMatrix();
	glTranslatef(50.0f,0.0f,0.0f);
	glutSolidSphere(r,30,30);
	glPopMatrix();
}

void Nube::dibujar()
{
	GLfloat blanco[]={1.0,1.0,1.0,1.0};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,blanco);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,blanco);
	GLfloat spec[] = {0.3f,0.3f,0.3f,1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
	GLfloat shininess[] = {15};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess);
	glColor3f(1.0f,1.0f,1.0f);
	for(int i=0;i<NUM_NUBES;i++)
	{
		glPushMatrix();
		glTranslatef(x[i],y[i],z[i]);
		dibujarNube(radio[i]);
		glPopMatrix();
	}
	if(nubeActiva && radioNueva > 1.0f)
	{
		glPushMatrix();
		glTranslatef(xNueva,yNueva,zNueva);
		dibujarNube(radioNueva);
		glPopMatrix();
	}
}

void Nube::actualizar()
{
	// Mover las nubes decorativas
	for(int i=0; i<NUM_NUBES; i++)
	{
		z[i] += velocidadNube[i];
		x[i] += sin(z[i]*0.02f)*0.02f;
		if(z[i] > 250.0f)
			z[i] = -250.0f;
	}
	
	// Mover la nube del ciclo
	if(vaporAcumulado >= 150 && radioNueva >= 22.0f)
	{
		zNueva += velocidadNueva;
		xNueva += sin(zNueva*0.02f)*0.03f;
	}
}

void Nube::agregarVapor()
{
	vaporAcumulado++;
	
	nubeActiva = true;
	
	radioNueva += 0.05f;
	
	if(radioNueva>22.0f)
		radioNueva=22.0f;
}
