#include "simulation.h"

//********************  Constructot simulation  ********************
simulation::simulation(uint rCount, string sMode, uint height, uint with) : p(height,with)
{
	robots = new robot[rCount];		// Genero la cantidad de robots que me indica rCount
	if (robots != NULL)
	{
		baldosasX = with;			// Numero de baldosas sobre el eje x
		baldosasY = height;			// Numero de baldosas sobre el eje y
		robotCounter = rCount;
		mode = sMode;

		for (int i = 0; i < rCount; i++)	// Inicializo todos los robots
		{
			robots[i].initRobot(height, with);
		}

		timeCount = 0;
		error.errNum = NO_ERROR;
	}
	else
	{
		error.errNum = NO_MEMORY;
		error.detail = "Not enough memory to create robots\n";
	}
		
}
//******************************************************************

//**********************  getMode  *********************************
string simulation::getMode(void)
{
	return mode;
}
//******************************************************************

//************************  step  **********************************
// step se encarga de hacer avanzar una posicion a todos los robots

void simulation::step(void)  
{
	point_t robotPos;
	for (int i = 0; i < robotCounter; i++)
	{
		robots[i].moveRobot();
		robotPos = robots[i].getRobotPos();
		if (p.isDirty((uint)floor(robotPos.x), (uint)floor(robotPos.y))) // Me fijo si esta sucia la baldosa donde va a ir el robot
		{
			p.cleanTile((uint)floor(robotPos.x), (uint)floor(robotPos.y)); // Si esta sucia se limpia
		}
	}

}
//******************************************************************

//*************************  simulate  *****************************
uint simulation::simulate(void)
{
	int i = 0;
	dibujator dib;
	do
	{
		step();					// Avanza los robots
		timeCount++;
		if (mode == "Mode 1")	// si o es mode 1 no tengo que mostrar la simulacion
		{
			dib.draw_mode(/*argumentos de entrada?*/);
			//delay
		}

	} while (p.countCleanTiles() != baldosasX * baldosasY);

	if (mode == "Mode 2")
	{
		dib.draw_mode(timeCount, robotCounter);
	}
	
	
	return timeCount;
}
//******************************************************************
uint simulation::tickCounter(void)
{
	return timeCount;
}

uint simulation::getRobotCounter(void)
{
	return robotCounter;
}

void simulation::destroy(void)
{
	delete robots[];
}
