#ifndef NUBE_H
#define NUBE_H

class Nube
{
private:
	
	static const int NUM_NUBES = 20;
	
	float x[NUM_NUBES];
	float y[NUM_NUBES];
	float z[NUM_NUBES];
	float radio[NUM_NUBES];
	
	float velocidadNube[NUM_NUBES];

	float xNueva;
	float yNueva;
	float zNueva;
	float radioNueva;
	float velocidadNueva;
	
	bool nubeActiva;
	int vaporAcumulado;

	
	void dibujarNube(float r);
	
public:
	
	Nube();
	void dibujar();
	void actualizar();
	void agregarVapor();
	bool listaParaMoverse();
};

#endif
