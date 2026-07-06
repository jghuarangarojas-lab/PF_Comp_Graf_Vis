#ifndef NUBE_H
#define NUBE_H

class Nube
{
private:
	
	static const int NUM_NUBES = 20;
	static const int NUM_GOTAS = 300;
	
	// Nubes decorativas
	float x[NUM_NUBES];
	float y[NUM_NUBES];
	float z[NUM_NUBES];
	float radio[NUM_NUBES];
	float velocidadNube[NUM_NUBES];
	
	// Nube formada por condensación
	float xNueva;
	float yNueva;
	float zNueva;
	
	float radioNueva;
	float velocidadNueva;
	
	bool nubeActiva;
	int vaporAcumulado;
	
	struct Gota
	{
		float x;
		float y;
		float z;
		
		float vx;
		float vy;
		float vz;
		
		bool activa;
	};
	
	Gota gotas[NUM_GOTAS];
	
	bool lluviaActiva;
	
	float vientoX;
	float vientoZ;
	
	void dibujarNube(float r);
	void emitirGota();
	
public:
	
	Nube();
	
	void dibujar();
	void actualizar();
	void agregarVapor();
};

#endif
