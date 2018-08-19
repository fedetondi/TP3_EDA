#include "draw.h"

/*     inicial_setup()
*	esta funcion se encarga de crear y verificar lo necesario para usar allegro
*	recibe:		nada
*	devuelve:	una estructura con lo necesario para allegro			//estos parametros se pueden cambiar desp
*/
bool dibujator::inicial_setup(uint w, uint h) //ver si en vez de devolver la estructura lo paso por referencia
{	

	if (al_init())
	{
		if (al_init_image_addon()) // el shut down de este addon lo hace automatico el programa al finalizar
		{
			if (al_init_primitives_addon())
			{
				display = al_create_display(HEITH, WIDE);	//tamaño random que puse yo para desp cambiarlo
				if (display != NULL)
				{
					//bitmap = (ALLEGRO_BITMAP *)malloc(w*h * sizeof(ALLEGRO_BITMAP));
					if ((pisoSucioBmp = al_load_bitmap("dirty.jpg")) != NULL) //ES PNG NO JPG!!
					{
						if ((pisoLimpioBmp = al_load_bitmap("clean.jpg")) != NULL)
						{
							if ((robotBmp = al_load_bitmap("robot.png")) != NULL)
							{
								if ((backBuffer = al_create_bitmap(UNIDAD / 2, UNIDAD / 2)) != NULL)
								{
									ok = true;
									sucioWidth = al_get_bitmap_width(pisoSucioBmp);
									sucioHeight = al_get_bitmap_height(pisoSucioBmp);

									limpioWidth = al_get_bitmap_width(pisoLimpioBmp);
									limpioHeight = al_get_bitmap_height(pisoLimpioBmp);

									printf("sucio0\t alto%d\t anco%d\n", sucioHeight, sucioWidth);
									printf("limpio0\t alto%d\t anco%d\n", limpioHeight, limpioWidth);


									auxWidth = al_get_bitmap_width(backBuffer);
									auxHeight = al_get_bitmap_height(backBuffer);
									printf("backBuffer\talto: %d\tancho: %d", auxHeight, auxWidth);

									robotWidth = al_get_bitmap_width(robotBmp);
									robotHeight = al_get_bitmap_height(robotBmp);
									printf("jacoby funciona todo bien ok, no es bloqueante \n");
									return ok;
								}
								al_destroy_bitmap(robotBmp);
								printf("No funciono backBuffer, es culpa de windows tambein, en linux no pasaba , \n");
							}
							al_destroy_bitmap(pisoLimpioBmp);
							printf("No funciono robot, es culpa de windows tambein, en linux no pasaba , \n");
						}
						al_destroy_bitmap(pisoSucioBmp);
						printf("No puedo cargar bien un puto bitmap, es cualpa de windows\n");
					}
					al_destroy_display(display);
					printf("no funciono el display, tambien es culpa de windows\n");
				}
				al_shutdown_primitives_addon();
			}
			al_shutdown_image_addon();
		}
	}
	printf("algo no funciono\n");
	/*pisoSucioBmp = al_create_bitmap(UNIDAD, UNIDAD);
	pisoLimpioBmp = al_create_bitmap(UNIDAD, UNIDAD);
	robotBmp = al_create_bitmap(UNIDAD, UNIDAD);
	backBuffer = al_create_bitmap(HEITH, WIDE);*/
	//pisoSucioBmp = NULL;

	ok = false;
	return ok;

	
}


//*********************  draw_mode1  *******************************
// La siguiente funcion se encarga de graficar el Modo 1, es decir,
// se encarga de imprimir el piso y los robots.
bool dibujator::draw_mode(robot* robots, piso& p, uint robotCounter)
{
	//pritnf("%p"´,pisosuciobmp)

	//printf("sucio\t alto: %d\t ancho: %d\n", sucioHeight, sucioWidth);
	//printf("limpio\t alto: %d\t ancho: %d\n", limpioHeight, limpioWidth);

	// Cargo en el buffer las baldosas 
	for (int i =0 ; (i < HEITH) && (i/UNIDAD < (double)p.getH()); i+= (UNIDAD))
	{
		for (int j = 0 ; (j < WIDE) && (j/UNIDAD < (double)p.getW()); j+= (UNIDAD) )
		{
			if(p.isDirty(i/UNIDAD,j/UNIDAD))
			{
				al_draw_scaled_bitmap(pisoSucioBmp, sucioWidth/2, sucioHeight/2, sucioWidth , sucioHeight, i , j, UNIDAD*2, UNIDAD*2, 0);
			}
			else
			{
				al_draw_scaled_bitmap(pisoLimpioBmp, limpioWidth / 2, limpioHeight / 2, limpioWidth, sucioHeight, i, j, UNIDAD*2, UNIDAD*2, 0);
			}
		}
	}

	// Cargo en el buffer los robots
	point_t robotPos;
	for (uint i = 0; i < robotCounter; i++)
	{
		al_set_target_bitmap(backBuffer);
		robots[i].moveRobot();
		robotPos = robots[i].getRobotPos();
		//al_draw_scaled_rotated_bitmap(robotBmp, robotWidth/2, robotHeight/2, robotPos.x + UNIDAD / 4 , robotPos.y + UNIDAD / 4 , UNIDAD / 2, UNIDAD / 2, robots[i].getRobotDir(), 0);		
		//al_draw_filled_circle(robotPos.x * UNIDAD, robotPos.y * UNIDAD, 7,al_map_rgb(50,255,255) );
		al_draw_scaled_rotated_bitmap(robotBmp, 0, 0, 0, 0, UNIDAD/2/*robotWidth / (2 * UNIDAD)*/, UNIDAD/2, robots[i].getRobotDir(), 0);
		//al_draw_bitmap(robotBmp, robotPos.x * UNIDAD, robotPos.y * UNIDAD, 0);
		//al_draw_scaled_bitmap(robotBmp, 0/*robotWidth / 2*/, 0/*robotHeight / 2*/, robotWidth, robotHeight, 0/*UNIDAD/4*/, 0, /*15*/UNIDAD/2, UNIDAD/2/*6*/, 0); //este por ahora maso va
		al_set_target_backbuffer(display);
		al_draw_bitmap(backBuffer, robotPos.x * UNIDAD, robotPos.y * UNIDAD, 0);
	}
	 
	al_flip_display();
	al_rest(0.1);
	return 0;
}
//******************************************************************

//*********************  draw_mode2  *******************************
// La siguiente funcion se encarga de graficar el Modo 2, es decir, 
// se encarga de imprimir la grafica del tiempo medio que demora la simulacion
bool dibujator::draw_mode(uint timeCount, uint robotCounter)
{
	// Coordenadas de la esquina superior izquierda del rectangulo
	float x1 = SPACE + robotCounter;
	float y1 = SPACE * timeCount;

	// Coordenadas de la esquina inferior derecha del rectangulo
	float x2 = x1 + WIDTH_RECTANGLE;
	float y2 = y1;

	//srand(time());

	ALLEGRO_COLOR color = al_map_rgb(50, 255, 255);
	printf("Entro, cuty puto si lees esto\n");
	
	al_draw_filled_rectangle(x1, y1 , x2, y2, color);
	al_flip_display();
	al_rest(5.0);
	//al_draw_filled_rectangle(esquina iz.x, esquina iz.y, esquina der.x, esquina der.y, color);*/
	return 0;
}
//******************************************************************
//*/
//**************************  finish  *******************************

void dibujator::finish(void)
{
	al_destroy_bitmap(pisoSucioBmp);
	al_destroy_bitmap(pisoLimpioBmp);
	al_destroy_bitmap(robotBmp);
	al_destroy_display(display);
	al_shutdown_image_addon();
}
//******************************************************************

/*

for(w = 0 ; w < wideMax ; w++){
	for(h = 0 ; h < heightMax ; h++){
		bitmap[i] = al_create_bitmap(w, h);
		i++;
	}
}

*/