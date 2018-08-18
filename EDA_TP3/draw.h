#ifndef DRAW_H
#define DRAW_H

extern "C"
{
	#include <allegro5/allegro.h>
	#include <allegro5/allegro_image.h>
}
#include "robot.h"
#include "piso.h"

#define HEITH 500
#define WIDE  500

typedef unsigned int uint;



class dibujator
{
	//aca dejo las imagenes que va a utilizar para dibujar
	ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *pisoSucioBmp;
	ALLEGRO_BITMAP *pisoLimpioBmp;
	ALLEGRO_BITMAP *robotBmp;
	ALLEGRO_BITMAP *backBuffer;
	bool ok;

public:
	bool inicial_setup(uint w, uint h);	
	bool draw_mode(robot* robots, piso& floor);
	bool draw_mode(uint nDeIteraciones);
};

#endif 

