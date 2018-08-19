#ifndef ROBOT_H
#define ROBOT_H

#include "definitions.h"

//*******  Estructura para coordenadas  *********
typedef struct
{
	double x;
	double y;
}point_t;
//**********************************************

//*************  Clase robot  ******************
class robot
{
	point_t pos;
	double dir;
	unsigned int hMax;
	unsigned int wMax;

public:

	void initRobot(unsigned int h, unsigned int w);
	void moveRobot(void);
	point_t getRobotPos(void);
	double getRobotDir(void);


};
//**********************************************
#endif
