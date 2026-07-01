#include "Texturas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Texturas::Texturas()
{
	
}

int Texturas::cargarTGA(const char* nombre, Textura* imagen)
{
	GLubyte cabeceraTGA[12] = {0,0,2,0,0,0,0,0,0,0,0,0};
	
	GLubyte compararTGA[12];
	
	GLubyte cabecera[6];
	
	GLuint bytesPorPixel;
	GLuint tamanoImagen;
	GLubyte temp;
	GLuint i;
	
	GLuint formato = GL_RGBA;
	
	FILE* archivo = fopen(nombre,"rb");
	
	if(!archivo)
	{
		printf("No se pudo abrir %s\n",nombre);
		return 0;
	}
	
	if(!archivo ||
	   fread(compararTGA,1,sizeof(compararTGA),archivo)!=sizeof(compararTGA) ||
	   memcmp(cabeceraTGA,compararTGA,sizeof(cabeceraTGA))!=0 ||
	   fread(cabecera,1,sizeof(cabecera),archivo)!=sizeof(cabecera))
	{
		if(archivo)
			fclose(archivo);
		
		return 0;
	}
	   
	   imagen->ancho = cabecera[1] * 256 + cabecera[0];
	   imagen->largo = cabecera[3] * 256 + cabecera[2];
	   imagen->bpp = cabecera[4];
	   
	   if(imagen->ancho<=0 ||
		  imagen->largo<=0 ||
		  (imagen->bpp!=24 && imagen->bpp!=32))
	   {
		   fclose(archivo);
		   return 0;
	   }
		  
		  bytesPorPixel = imagen->bpp/8;
		  
		  tamanoImagen = imagen->ancho *
			  imagen->largo *
			  bytesPorPixel;
		  
		  imagen->dibujo = (GLubyte*)malloc(tamanoImagen);
		  
		  if(imagen->dibujo==NULL)
		  {
			  fclose(archivo);
			  return 0;
		  }
		  
		  if(fread(imagen->dibujo,1,tamanoImagen,archivo)!=tamanoImagen)
		  {
			  free(imagen->dibujo);
			  fclose(archivo);
			  return 0;
		  }
		  
		  fclose(archivo);
		  
		  for(i=0;i<tamanoImagen;i+=bytesPorPixel)
		  {
			  temp = imagen->dibujo[i];
			  
			  imagen->dibujo[i] = imagen->dibujo[i+2];
			  
			  imagen->dibujo[i+2] = temp;
		  }
		  
		  glGenTextures(1,&imagen->ID);
		  
		  glBindTexture(GL_TEXTURE_2D,imagen->ID);
		  
		  if(imagen->bpp==24)
			  formato=GL_RGB;
		  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
		  glTexImage2D(
					   GL_TEXTURE_2D,
					   0,
					   formato,
					   imagen->ancho,
					   imagen->largo,
					   0,
					   formato,
					   GL_UNSIGNED_BYTE,
					   imagen->dibujo
					   );
		  
		  // Filtros
		  
		  glTexParameteri(GL_TEXTURE_2D,
						  GL_TEXTURE_MIN_FILTER,
						  GL_LINEAR);
		  
		  glTexParameteri(GL_TEXTURE_2D,
						  GL_TEXTURE_MAG_FILTER,
						  GL_LINEAR);
		  
		  // Repetición
		  
		  glTexParameteri(GL_TEXTURE_2D,
						  GL_TEXTURE_WRAP_S,
						  GL_REPEAT);
		  
		  glTexParameteri(GL_TEXTURE_2D,
						  GL_TEXTURE_WRAP_T,
						  GL_REPEAT);
		  
#ifdef GL_GENERATE_MIPMAP
		  glTexParameteri(GL_TEXTURE_2D,
						  GL_GENERATE_MIPMAP,
						  GL_TRUE);
#endif
		  
		  // Liberamos RAM
		  
		  free(imagen->dibujo);
		  
		  imagen->dibujo = NULL;
		  
		  return 1;
}

void Texturas::cargarTexturas()
{
	cargarTGA("Texturas/cielo.tga",&cielo);
	
	cargarTGA("Texturas/pasto.tga",&pasto);
	if(!cargarTGA("Texturas/pasto.tga",&pasto)) printf("Error cargando pasto\n");
	
	cargarTGA("Texturas/agua.tga",&agua);
	if(!cargarTGA("Texturas/agua.tga",&agua)) printf("Error cargando agua\n");
	
	cargarTGA("Texturas/roca.tga",&roca);
	
	cargarTGA("Texturas/arena.tga",&arena);
}

GLuint Texturas::getCielo()
{
	return cielo.ID;
}

GLuint Texturas::getPasto()
{
	return pasto.ID;
}

GLuint Texturas::getAgua()
{
	return agua.ID;
}

GLuint Texturas::getRoca()
{
	return roca.ID;
}

GLuint Texturas::getArena()
{
	return arena.ID;
}
