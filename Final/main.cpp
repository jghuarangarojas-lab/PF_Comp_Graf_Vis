#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "Sol.h"
# include "Terreno.h"
# include "Texturas.h"
# include "Rio.h"
# include "Nube.h"
# include "Vapor.h"
# include "Camara.h"
# include "Lago.h"
# include "Montanas.h"
# include <ctime>
#endif

Montanas montanas;
Texturas texturas;
Sol sol;
Terreno terreno;
Rio rio;
Lago lago;
Nube nube;
Vapor vapor;
Camara camara;

bool mostrarAyuda = true;
int anchoVentana = 700;
int altoVentana = 700;

void dibujarTexto(float x, float y, const char* texto);
void dibujarAyuda();

void timer(int value)
{
	nube.actualizar();
	rio.actualizar();
	int nuevas = vapor.actualizar();
	
	for(int i=0; i<nuevas; i++)
	{
		nube.agregarVapor();
	}
	glutTimerFunc(15,timer,0);
	glutPostRedisplay();
}

void dibujarTexto(float x, float y, const char* texto) {
	glRasterPos2f(x, y);
	for (int i = 0; texto[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[i]);
	}
}

void dibujarAyuda() {
	if (!mostrarAyuda) return;
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, anchoVentana, 0, altoVentana);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	glColor3f(1, 1, 1);
	int y = altoVentana - 30;
	int paso = 22;
	dibujarTexto(10, y, "CONTROLES");     y -= paso;
	dibujarTexto(10, y, "W / A / S / D: Mover");  y -= paso;
	dibujarTexto(10, y, "Q / E: Subir / Bajar");  y -= paso;
	dibujarTexto(10, y, "Flechas: Rotar");        y -= paso;
	dibujarTexto(10, y, "R: Reiniciar camara");   y -= paso;
	dibujarTexto(10, y, "H: Ocultar / Mostrar");  y -= paso;
	dibujarTexto(10, y, "ESC: Salir");            y -= paso;
	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void teclado_cb(unsigned char key, int x, int y) {
	float paso = 5.0f;
	
	switch (key) {
	case 'w': case 'W': camara.avanzar(paso);   break;
	case 's': case 'S': camara.avanzar(-paso);  break;
	case 'a': case 'A': camara.strafe(-paso);   break;
	case 'd': case 'D': camara.strafe(paso);    break;
	case 'q': case 'Q': camara.elevar(paso);    break;
	case 'e': case 'E': camara.elevar(-paso);   break;
	case 'r': case 'R': camara.reiniciar();     break;
	case 'h': case 'H': mostrarAyuda = !mostrarAyuda; break;
	case 27: exit(0); break; 
	}
	glutPostRedisplay();
}

void tecladoEspecial_cb(int key, int x, int y) {
	float angulo = 0.05f;
	
	switch (key) {
	case GLUT_KEY_LEFT:  camara.rotarYaw(-angulo);   break;
	case GLUT_KEY_RIGHT: camara.rotarYaw(angulo);    break;
	case GLUT_KEY_UP:    camara.rotarPitch(angulo);  break;
	case GLUT_KEY_DOWN:  camara.rotarPitch(-angulo); break;
	}
	glutPostRedisplay();
}

void reshape_cb (int w, int h) {
	if (w==0||h==0) return;
	anchoVentana = w;
	altoVentana = h;
	glViewport(0,0,w,h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(45.0,(GLfloat)w/(GLfloat)h,1.0,1000.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void display_cb() {	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
			  0.0, 120.0, 280.0,   // Posición de la cámara
			  0.0, 0.0, 0.0,       // Punto al que mira
			  0.0, 1.0, 0.0        // Vector "arriba"
			  );
	GLfloat blanco[] = {1,1,1,1};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,blanco);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,blanco);
	GLfloat mat_specular[]={1,1,1,1};
	GLfloat mat_shininess[]={100};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);//COLOR DEL BRILLO
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);//REGULADOR DEL BRILLO
//	srand(time(NULL));
	camara.dibujar();
	sol.iluminar();
	terreno.dibujar(texturas.getPasto());
 	montanas.dibujar(texturas.getRoca());
    rio.dibujar(texturas.getAgua());
	lago.dibujar(texturas.getAgua());
	sol.dibujar();
	nube.dibujar();
	vapor.dibujar();

	glutSwapBuffers();
}

void initialize() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (anchoVentana,altoVentana);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Simulación del ciclo del agua.");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat luzGlobal[] = {0.45f,0.45f,0.45f,1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luzGlobal);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	texturas.cargarTexturas();
	glutDisplayFunc (display_cb);
	glutReshapeFunc (reshape_cb);
	glutKeyboardFunc(teclado_cb);
	glutSpecialFunc(tecladoEspecial_cb);
	glClearColor(0.53f,0.81f,0.98f,1.0f);
	//glClearColor(0,0,0,1.0f);
	glutTimerFunc(15,timer,0);
}

int main (int argc, char **argv) {
	glutInit (&argc, argv);
	initialize();
	glutMainLoop();
	return 0;
}
