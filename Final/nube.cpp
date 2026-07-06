#include "Nube.h"
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

Nube::Nube()
{
	for(int i=0;i<NUM_NUBES;i++)
	{
		x[i]=-120+rand()%240;
		y[i]=100+rand()%25;
		z[i]=120+rand()%70;
		
		radio[i]=20.0f;
		
		velocidadNube[i]=0.02f+(rand()%5)*0.01f;
	}
	
	xNueva=0;
	yNueva=90;
	zNueva=-230;
	
	radioNueva=0;
	
	velocidadNueva=0.03f;
	
	nubeActiva=false;
	
	vaporAcumulado=0;
	
	lluviaActiva=false;
	
	vientoX=0.02f;
	vientoZ=-0.01f;
	
	for(int i=0;i<NUM_GOTAS;i++)
		gotas[i].activa=false;
}
void Nube::emitirGota()
{
	for(int i=0;i<NUM_GOTAS;i++)
	{
		if(!gotas[i].activa)
		{
			gotas[i].activa=true;
			
			gotas[i].x=xNueva+(rand()%50-25);
			gotas[i].y=yNueva;
			gotas[i].z=zNueva+(rand()%50-25);
			
			gotas[i].vx=vientoX+(rand()%10-5)*0.003f;
			
			gotas[i].vz=vientoZ+(rand()%10-5)*0.003f;
			
			gotas[i].vy=-(0.45f+(rand()%25)*0.02f);
			
			break;
		}
	}
}
void Nube::dibujarNube(float r)
{
	glPushMatrix();
	glutSolidSphere(r,30,30);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(25,5,0);
	glutSolidSphere(r+6,30,30);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(50,0,0);
	glutSolidSphere(r,30,30);
	glPopMatrix();
}
void Nube::dibujar()
{
	GLfloat blanco[]={1,1,1,1};
	GLfloat gris[]={0.55f,0.55f,0.60f,1};

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,blanco);
	GLfloat shininess[]={15};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shininess);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,blanco);
	
	glColor3f(1,1,1);
	
	for(int i=0;i<NUM_NUBES;i++)
	{
		glPushMatrix();
		glTranslatef(x[i],y[i],z[i]);
		dibujarNube(radio[i]);
		glPopMatrix();
	}
	
	if(nubeActiva)
	{
		if(lluviaActiva)
		{
			glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,gris);
			
			glColor3f(0.55f,0.55f,0.60f);
		}
		else
		{
			glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,blanco);
			
			glColor3f(1,1,1);
		}
		
		glPushMatrix();
		
		glTranslatef(xNueva,yNueva,zNueva);
		
		dibujarNube(radioNueva);
		
		glPopMatrix();
	}
	
	glDisable(GL_LIGHTING);
	
	glColor3f(0.65f,0.75f,1.0f);
	
	glBegin(GL_LINES);
	
	for(int i=0;i<NUM_GOTAS;i++)
	{
		if(!gotas[i].activa)
			continue;
		
		glVertex3f(gotas[i].x,gotas[i].y,gotas[i].z);
		glVertex3f(gotas[i].x,gotas[i].y+2.5f,gotas[i].z);
	}
	
	glEnd();
	
	glEnable(GL_LIGHTING);
}
void Nube::actualizar()
{
	for(int i=0;i<NUM_NUBES;i++)
	{
		z[i]+=velocidadNube[i];
		
		x[i]+=sin(z[i]*0.02f)*0.03f;
		
		if(z[i]>250)
			z[i]=-250;
	}
	
	if(vaporAcumulado>=150 &&
	   radioNueva>=22.0f)
	{
		lluviaActiva=true;
		
		zNueva+=velocidadNueva;
		
		xNueva+=sin(zNueva*0.02f)*0.03f;
	}
	if(zNueva>250){
		zNueva=-250;
		vaporAcumulado = 0;
	}
	
	if(lluviaActiva)
	{
		for(int i=0;i<5;i++)
			emitirGota();
		
		for(int i=0;i<NUM_GOTAS;i++)
		{
			if(!gotas[i].activa)
				continue;
			
			gotas[i].x+=gotas[i].vx;
			gotas[i].y+=gotas[i].vy;
			gotas[i].z+=gotas[i].vz;
			
			if(gotas[i].y<-40)
				gotas[i].activa=false;
		}
	}
}
void Nube::agregarVapor()
{
	vaporAcumulado++;
	
	nubeActiva=true;
	
	radioNueva+=0.05f;
	
	if(radioNueva>22.0f)
		radioNueva=22.0f;
}
