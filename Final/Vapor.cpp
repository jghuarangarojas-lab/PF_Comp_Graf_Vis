#include "Vapor.h"
#include <cstdlib>
#include <GL/glut.h>
#include <ctime>
Vapor::Vapor()
{
	origenX = 0.0f;
	origenY = -39.4f;
	origenZ = -235.0f;

	contadorEmision = 0;
	for(int i=0;i<MAX_PARTICULAS;i++){
		particulas[i].activa=false;
	}
}

void Vapor::emitir()
{
	
	for(int i=0;i<MAX_PARTICULAS;i++)
	{
		if(!particulas[i].activa)
		{
			particulas[i].activa=true;
			
			particulas[i].x=origenX+(rand()%20-10);
			
			particulas[i].y=origenY;
			
			particulas[i].z=origenZ+(rand()%20-10);
			
			particulas[i].vx += ((rand()%3)-1)*0.001f;
			
			particulas[i].vy = 0.55f;
			
			particulas[i].vz += ((rand()%3)-1)*0.001f;
			
			particulas[i].vida=1.0f;
			
			break;
		}
	}
}

int Vapor::actualizar()
{
	contadorEmision++;
	
	if(contadorEmision >= 3)
	{
		emitir();
		contadorEmision = 0;
	}
	int condensadas = 0;
	for(int i=0;i<MAX_PARTICULAS;i++)
	{
		if(!particulas[i].activa)
			continue;
		
		particulas[i].x += particulas[i].vx;
		particulas[i].y += particulas[i].vy;
		particulas[i].z += particulas[i].vz;
		
		particulas[i].vida -= 0.003f;
		
		if(particulas[i].vida <= 0.0f)
		{
			particulas[i].activa = false;
			continue;
		}
		if(particulas[i].y > 75.0f)
		{
			particulas[i].vida -= 0.01f;
		}
		if(particulas[i].y >= ALTURA_CONDENSACION)
		{
			//nube.agregarVapor();
			condensadas++;
			particulas[i].activa = false;
		}
	}
	return condensadas;
}

void Vapor::dibujar()
{
	glDisable(GL_LIGHTING);
	
	glPointSize(20);
	
	glBegin(GL_POINTS);
	
	for(int i=0;i<MAX_PARTICULAS;i++)
	{
		if(!particulas[i].activa)
			continue;
		
		glColor4f(0.9f,0.9f,0.9f,particulas[i].vida);
		glVertex3f(particulas[i].x,particulas[i].y,particulas[i].z);
	}
	
	glEnd();
	
	glEnable(GL_LIGHTING);
}
