#include "Sol.h" 
#include <GL/glut.h> 
#include <iostream> 
Sol::Sol() { 
	x = 100.0f; 
	y = 180.0f; 
	z = -150.0f; 
	radio = 50.0f; 
} 
void Sol::dibujar() { 
	glPushMatrix(); 
	// Posición del sol 
	glTranslatef(x, y, z); 
	// Color amarillo 
	glColor3f(1.0f, 1.0f, 0.0f); 
	GLfloat amarillo[] = {1,1,0,1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amarillo);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,amarillo);
	GLfloat emision[] = {1.0f,1.0f,0.2f,1.0f};
	//glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emision);
	GLfloat mat_specular[]={1,1,0,1};
	GLfloat mat_shininess[]={100};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);//COLOR DEL BRILLO
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);//REGULADOR DEL BRILLO
	GLfloat apagar[] = {0,0,0,1};
	//glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,apagar);
	// Esfera 
	glutSolidSphere(radio, 50, 50); 
	glPopMatrix(); 
} 
void Sol::iluminar() { 
	GLfloat posicion[] = {x,y,z,1.0f}; 
	GLfloat difusa[] = {1.0f,1.0f,0.0f,1.0f}; 
	GLfloat ambiente[] = {0.5f,0.5f,0.5f,1.0f}; 
	glLightfv(GL_LIGHT0, GL_POSITION, posicion); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa); 
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente); 
	glEnable(GL_LIGHT0); 
}
