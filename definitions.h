#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>
#include <cstdlib>

#define PI 3.141592653
#define UNIDAD 30.0
#define SPACE 3.0
#define WIDTH_RECTANGLE 3.0
#define RADIO 0.5
using namespace::std;

//************  Tipos de errores  *****************
/* NO_ERROR = 0
 * NO_MEMORY = 1
 * PARSE_ERROR = 2
 */
typedef enum { NO_ERROR, NO_MEMORY, PARSE_ERROR }errNo;
//*************************************************

//******  Estructura para guardar error  ********
typedef struct
{
	string detail;
	errNo errNum;
}errType;
//**********************************************



#endif