#include "robot.h"
#include <ctime>
#include <cstdlib>
#include <cmath>


//*********************  initRobot  ********************************
void robot::initRobot(unsigned int h, unsigned int w)

// Para inicializar la un robot hace falta asignarle una posicion en el tablero y un angulo de direccion
{
	hMax = h;
	wMax = w;
	pos.x = (( rand() % (wMax * 10 ) ) /* UNIDAD*/) / 10.0;	// Asigna una posicion al azar en el tablero
	pos.y = (( rand() % (hMax * 10 ) ) /* UNIDAD*/) / 10.0;
 
	dir = (rand() % 360) * 2 * PI / 360;				// Genero una direccion y la paso a radianes va de 0 a 2PI
	printf("robot x : %f , robot y : %f, direccion: %f \n", pos.x, pos.y, dir);
	printf("floor(pos.x) = %d / %f \n", (unsigned int) floor(pos.x), floor(pos.x));
}
//******************************************************************

//*********************  moveRobot  ********************************
void robot::moveRobot(void)
{
	double xtemp, ytemp;
	xtemp = pos.x + (0.1 * cos(dir));
	ytemp = pos.y + (0.1 * sin(dir));
	if ( (xtemp-0.2) >= 0 && (xtemp+0.2) < wMax && (ytemp-0.2) >= 0 && (ytemp+0.2) < hMax) // Se fija si el robot esta adentro de las baldosas...  agregue el 0.2 que deesp se puede sacar
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
	return pos;
}
//******************************************************************

double robot::getRobotDir(void) 
{
	return dir;
}