#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include "robot.h"
#include "piso.h"
#include "draw.h"

class simulation
{
	unsigned int timeCount;
	uint baldosasX;
	uint baldosasY;
	string mode;
	unsigned int robotCounter;
	robot * robots;
	piso p;
	errType error;
public:

	simulation(uint rCount, string sMode, uint height, uint with);
	string getMode(void);
	void step(void);
	uint simulate(void);
	uint tickCounter(void);
	uint getRobotCounter(void);
	void destroy(void);


};

#endif
