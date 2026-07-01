#ifndef CAMARA_H
#define CAMARA_H

class Camara {
private:
	float x, y, z;     // Posicion de la camara
	float angH, angV;  // Angulos para mirar (Horizontal / Vertical)
public:
	Camara();
	void dibujar();
	void actualizar();
	void avanzar(float paso);      // W / S
	void strafe(float paso);       // A / D
	void elevar(float paso);       // Q / E
	void rotarYaw(float angulo);   // Flechas Izq / Der
	void rotarPitch(float angulo); // Flechas Arriba / Abajo
	void reiniciar();              // Tecla R
};

#endif
