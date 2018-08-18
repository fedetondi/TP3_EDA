#include "piso.h"
#include "robot.h"
#include "simulation.h"
#include <string>

using namespace::std;

typedef struct   // esta seria la estructura para guardar las cosas del parse
{
	string simulationMode;  // no se pq hay problemas con el tipo de dato string
	uint robotNum;
	uint baldosasX;
	uint baldosasY;
	errType errorParse;
}arguments;

int main(int argc, char * argv)
{
	
	arguments arg;
/*    hago las cosas del parse
 *		hay qu ever el parseCMD de que grupo usamos 
 *		hay que hacer el callback
 *		metemos todo en arguments 
 *		hay que ver si la validacion de los datos la hacemos en el callback o en una funcion aparte
 */
	if(arg.simulationMode == "Mode 1")
	{
		simulation sim(arg.robotNum, arg.simulationMode, arg.baldosasY, arg.baldosasX); // hay que ver cual es x y cual es y, me lo confundo a veces
		uint tickCounter = sim.simulate();
		// mustro la cantidad de ticks
		sim.destroy();
	}
	else
	{
		double tickcounter[1000] = { 0 }; // arreglo para guardar los tiepos promedios
		for (int n = 1; abs(tickcounter[n] - tickcounter[n - 1]) > 0.1 && n < 1000; n++)
		{
			for (int i = 0; i < 1000; i++) //hago las 1000 iteraciones
			{
				simulation sim(arg.robotNum, arg.simulationMode, arg.baldosasY, arg.baldosasX);
				tickcounter[n - 1] += sim.simulate();
				sim.destroy();
			}
			tickcounter[n - 1] /= 1000.0; // hago el promedio
			// dibujo la barra para esta cantidad de robots
		}
	}
	return 0;

}