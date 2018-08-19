#ifndef SIMULATION_H
#define SIMULATION_H

#include "definitions.h"
#include "robot.h"
#include "piso.h"
#include "draw.h"

class simulation
{
	uint timeCount;
	uint baldosasX;
	uint baldosasY;
	string mode;
	uint robotCounter;
	robot * robots;
	piso p;
	dibujator dib;
	errType error;
public:

	simulation(uint rCount, string sMode, uint height, uint with);
	string getMode(void);
	void step(void);
	uint simulate(void);
	uint tickCounter(void);
	//uint getRobotCounter(void);
	void destroy(void);


};

#endif
