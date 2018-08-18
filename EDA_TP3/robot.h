#ifndef ROBOT_H
#define ROBOT_H

#include <string>

#define PI 3.141592653
#define UNIDAD 30
using namespace::std;

//************  Tipos de errores  *****************
/* NO_ERROR = 0 
 * NO_MEMORY = 1
 * PARSE_ERROR = 2
 */
typedef enum{NO_ERROR, NO_MEMORY, PARSE_ERROR}errNo;
//*************************************************

//******  Estructura para guardar error  ********
typedef struct
{
	string detail;
	errNo errNum;
}errType;
//**********************************************

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

};
//**********************************************
#endif
