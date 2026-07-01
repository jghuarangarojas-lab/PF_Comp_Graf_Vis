#ifndef VAPOR_H
#define VAPOR_H

class Vapor
{
private:
	
	struct Particula
	{
		float x;
		float y;
		float z;
		
		float vx;
		float vy;
		float vz;
		
		float vida;
		
		bool activa;
	};
	
	static const int MAX_PARTICULAS = 250;
	const float ALTURA_CONDENSACION = 90.0f;
	Particula particulas[MAX_PARTICULAS];
	int contadorEmision;
	float origenX;
	float origenY;
	float origenZ;
	
public:
	
	Vapor();
	
	int actualizar();
	void dibujar();
	void emitir();
	
};
#endif
