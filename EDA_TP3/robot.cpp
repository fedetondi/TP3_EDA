#include "robot.h"
#include <ctime>
#include <cstdlib>
#include <cmath>


//*********************  initRobot  ********************************
void robot::initRobot(unsigned int h, unsigned int w)

// Para inicializar la un robot hace falta asignarle una posicion en el tablero y un angulo de direccion
{
	srand(time(NULL));
	hMax = h;
	wMax = w;
	pos.x = ( rand() % (wMax * 10 ) ) * UNIDAD / 10.0;	// Asigna una posicion al azar en el tablero
	pos.y = ( rand() % (hMax * 10 ) ) * UNIDAD / 10.0;	
	dir = (rand() % 360) * 2 * PI / 360;				// Genero una direccion y la paso a radianes va de 0 a 2PI
}
//******************************************************************

//*********************  moveRobot  ********************************
void robot::moveRobot(void)
{
	double xtemp, ytemp;
	xtemp = pos.x + UNIDAD * cos(dir);
	ytemp = pos.y + UNIDAD * sin(dir);
	if ( xtemp >= 0 && xtemp < wMax && ytemp >= 0 && ytemp < hMax) // Se fija si el robot esta adentro de las baldosas
	{
		pos.x = xtemp;
		pos.y = ytemp;
		 
	}
	else // Si el robot no esta dentro de las baldosas, significa que hay un pared
	{
		dir = (rand() % 360) * 2 * PI / 360; // No cambio la posicion y sorteo una direccion nueva
	}
}
//******************************************************************

//********************  getRobotPos  *******************************
point_t robot::getRobotPos(void)
{
	return point_t();
}
//******************************************************************