#include "Camara.h"
#include <GL/glut.h>
#include <cmath>

Camara::Camara() {
	x = 0.0f;  y = 80.0f; z = 250.0f; // Posicion inicial
	angH = 0.0f; angV = 0.0f;
}

void Camara::dibujar() {
	// Calculo para saber a donde mira la camara
	float mirarX = sin(angH) * cos(angV);
	float mirarY = sin(angV);
	float mirarZ = -cos(angH) * cos(angV);
	
	// Aplicar la vista
	gluLookAt(x, y, z, x + mirarX, y + mirarY, z + mirarZ, 0, 1, 0);
}

void Camara::avanzar(float paso) {
	x += sin(angH) * paso;
	z -= cos(angH) * paso;
}

void Camara::strafe(float paso) {
	x += cos(angH) * paso;
	z += sin(angH) * paso;
}

void Camara::elevar(float paso) {
	y += paso;
}

void Camara::rotarYaw(float angulo) {
	angH += angulo;
}

void Camara::rotarPitch(float angulo) {
	angV += angulo;
	if (angV > 1.5f)  angV = 1.5f;  // Tope para no dar la vuelta completa
	if (angV < -1.5f) angV = -1.5f; 
}

void Camara::reiniciar() {
	x = 0.0f;  y = 80.0f; z = 250.0f;
	angH = 0.0f; angV = 0.0f;
}
