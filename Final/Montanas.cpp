#include "Montanas.h"

Montanas::Montanas()
{
}

void Montanas::dibujarMontana(float x,float z,float base,float altura,GLuint textura)
{
	float yBase=-40.0f;
	float mitad=base/2.0f;
	
	//---------------------------------
	// Material
	//---------------------------------
	
	GLfloat rocaDifusa[]={1,1,1,1};
	GLfloat rocaAmbiente[]={0.6f,0.6f,0.6f,1};
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,rocaDifusa);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,rocaAmbiente);
	
	//---------------------------------
	// Textura
	//---------------------------------
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textura);
	
	glBegin(GL_TRIANGLES);
	
	//========================
	// Frente
	//========================
	
	glNormal3f(0.0f,0.7f,0.7f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x-mitad,yBase,z-mitad);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x+mitad,yBase,z-mitad);
	
	glTexCoord2f(0.5f,1.0f);
	glVertex3f(x,yBase+altura,z);
	
	//========================
	// Derecha
	//========================
	
	glNormal3f(0.7f,0.7f,0.0f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x+mitad,yBase,z-mitad);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x+mitad,yBase,z+mitad);
	
	glTexCoord2f(0.5f,1.0f);
	glVertex3f(x,yBase+altura,z);
	
	//========================
	// Atrás
	//========================
	
	glNormal3f(0.0f,0.7f,-0.7f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x+mitad,yBase,z+mitad);
	
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x-mitad,yBase,z+mitad);
	
	glTexCoord2f(0.5f,1.0f);
	glVertex3f(x,yBase+altura,z);
	
	//========================
	// Izquierda
	//========================
	
	glNormal3f(-0.7f,0.7f,0.0f);
	
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x-mitad,yBase,z+mitad);
	
	glTexCoord2f(2.0f,0.0f);
	glVertex3f(x-mitad,yBase,z-mitad);
	
	glTexCoord2f(1.0f,2.0f);
	glVertex3f(x,yBase+altura,z);
	
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	
	//---------------------------------
	// Nieve
	//---------------------------------
	
	GLfloat nieve[]={1,1,1,1};
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,nieve);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,nieve);
	
	float h=altura*0.75f;
	
	glBegin(GL_TRIANGLES);
	
	// Frente
	
	glNormal3f(0.0f,0.7f,0.7f);
	
	glVertex3f(x-15,yBase+h,z-15);
	glVertex3f(x+15,yBase+h,z-15);
	glVertex3f(x,yBase+altura,z);
	
	// Derecha
	
	glNormal3f(0.7f,0.7f,0.0f);
	
	glVertex3f(x+15,yBase+h,z-15);
	glVertex3f(x+15,yBase+h,z+15);
	glVertex3f(x,yBase+altura,z);
	
	// Atrás
	
	glNormal3f(0.0f,0.7f,-0.7f);
	
	glVertex3f(x+15,yBase+h,z+15);
	glVertex3f(x-15,yBase+h,z+15);
	glVertex3f(x,yBase+altura,z);
	
	// Izquierda
	
	glNormal3f(-0.7f,0.7f,0.0f);
	
	glVertex3f(x-15,yBase+h,z+15);
	glVertex3f(x-15,yBase+h,z-15);
	glVertex3f(x,yBase+altura,z);
	
	glEnd();
}

void Montanas::dibujar(GLuint textura)
{
	glPushMatrix();
	
	dibujarMontana(-140.0f,210.0f,120.0f,120.0f,textura);
	dibujarMontana(0.0f,230.0f,180.0f,170.0f,textura);
	dibujarMontana(140.0f,205.0f,130.0f,130.0f,textura);
	
	glPopMatrix();
}
