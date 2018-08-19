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
		//printf("la baldosa (%d,%d) esta  %d\n", (uint)floor(robotPos.x), (uint)floor(robotPos.y), p.isDirty((uint)floor(robotPos.x), (uint)floor(robotPos.y)));
	    
		p.cleanTile((uint)floor(robotPos.x/*UNIDAD*/), (uint)floor(robotPos.y/*UNIDAD*/));
		/*
			if (p.isDirty((uint)floor(robotPos.x), (uint)floor(robotPos.y))) // Me fijo si esta sucia la baldosa donde va a ir el robot
		{
			p.cleanTile((uint)floor(robotPos.x), (uint)floor(robotPos.y)); // Si esta sucia se limpia
		}
		*/
	}

}
//******************************************************************

//*************************  simulate  *****************************
uint simulation::simulate(void)
{
	//int n = 1;
	//double tickCounter[1000] = { 0 };
	//double tickCounter[2] = { 0.0 , 0.0 };
	//double tickCmp[2] = { 0.0 , 0.0 };
	dib.inicial_setup(baldosasX, baldosasY); 
	/*do 
	{
		for (int n = 0; n < 1000; n++)
		{*/
			//tickCounter[0] = tickCounter[1];
			do
			{
				step();					// Avanza los robots
				timeCount++;
				if (mode == "Mode 1")	// si o es mode 1 no tengo que mostrar la simulacion
				{
					dib.draw_mode(robots, p, robotCounter);
				}
			} while (p.countCleanTiles() != baldosasX * baldosasY);
			//tickCounter[1] += timeCount;
			//robotCounter++;
		/*}
		//tickCmp[0] = tickProm(tickCounter);
		tickCounter[1] /= 1000;
	} while (mode == "Mode 2" && abs(tickCounter[0] - tickCounter[1]) > 0.1);
	*/
/*
	if (mode == "Mode 2")
	{
		printf("entro\n");
		dib.draw_mode(timeCount, robotCounter);
	}
	
	*/
	return timeCount;
}
//******************************************************************
uint simulation::tickCounter(void)
{
	return timeCount;
}

/*uint simulation::getRobotCounter(void)
{
	return robotCounter;						//sacarlo porque no lo estamos usando
}*/


void simulation::destroy(void)
{
	delete []robots;
}
