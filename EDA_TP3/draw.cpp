#include "draw.h"

/*     inicial_setup()
*	esta funcion se encarga de crear y verificar lo necesario para usar allegro
*	recibe:		nada
*	devuelve:	una estructura con lo necesario para allegro			//estos parametros se pueden cambiar desp
*/
bool dibujator::inicial_setup(uint w, uint h){	//ver si en vez de devolver la estructura lo paso por referencia

	if (al_init())
	{
		if (al_init_image_addon()) // el shut down de este addon lo hace automatico el programa al finalizar
		{
			display = al_create_display(HEITH,WIDE);	//tamaño random que puse yo para desp cambiarlo
			if(display != NULL)
			{
				//bitmap = (ALLEGRO_BITMAP *)malloc(w*h * sizeof(ALLEGRO_BITMAP));
				ok = true;
				return ok;
				else{
					al_destroy_display(display);
				}
			}

		}
	}

	pisoSucioBmp = al_create_bitmap(UNIDAD, UNIDAD);
	pisoLimpioBmp = al_create_bitmap(UNIDAD, UNIDAD);
	robotBmp = al_create_bitmap(UNIDAD, UNIDAD);
	backBuffer = al_create_bitmap(HEITH, WIDE);

	ok = false;
	return ok;

	
}


//*********************  draw_mode1  *******************************
// La siguiente funcion se encarga de graficar el Modo 1, es decir,
// se encarga de imprimir el piso y los robots.
bool dibujator::draw_mode(robot* robots, piso& floor)
{
	// Cargo en el buffer las baldosas 
	for (int i = 0; i < HEITH; i+=UNIDAD)		
	{
		for (int j = 0; j < WIDE; j+=UNIDAD)
		{
			if(floor.isDirty(i,j))
			{
				backbuffer = al_draw_bitmap(pisoSucioBmp, i, j, 0);
			}
			else
			{
				backbuffer = al_draw_bitmap(pisoLimpioBmp, i, j, 0);
			}
		}
	}

	// Cargo en el buffer los robots
	point_t robotPos;
	for (int i = 0; i < robotCounter; i++)
	{
		robots[i].moveRobot();
		robotPos = robots[i].getRobotPos();
		backbuffer = al_draw_rotated_bitmap(robotBmp, 0, 0, robotPos.x, robotPos.y, /*Robotdir*/, 0);
	}
	
	al_flip_display();

}
//******************************************************************

//*********************  draw_mode1  *******************************
// La siguiente funcion se encarga de graficar el Modo 2, es decir, 
// se encarga de imprimir la grafica del tiempo medio que demora la simulacion
bool dibujator::draw_mode(uint nDeIteraciones,)
{


}



/*

for(w = 0 ; w < wideMax ; w++){
	for(h = 0 ; h < heightMax ; h++){
		bitmap[i] = al_create_bitmap(w, h);
		i++;
	}
}

*/