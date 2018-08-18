#include "piso.h"

//**********************  Constructor piso  ************************
piso::piso(uint hCount, uint wCount)
{
	h = hCount;
	w = wCount;
	baldosa = (bool *)malloc(h*w * sizeof(bool));
	if (baldosa != NULL)
	{
		for (int i = 0; i < w*h; i++)
		{
			baldosa[i] = true;
		}
	}
	else
	{
		error.errNum = NO_MEMORY;
		error.detail = "Not enough memory in floor construction\n";
	}
}
//******************************************************************

//**********************  isDirty  *********************************
// Funcion que se fija si la baldosa esta sucia
// Devuelve un false si esta limpio y devuelve un true si esta sucio
bool piso::isDirty(uint x, uint y)
{
	if ((x < w) && (y < h))
	{
		return baldosa[x + y * w];
	}
}
//******************************************************************

//**********************  isFloorClean******************************
// Funcion que se fija si el piso esta limpio
// Devuelve un false si esta sucio y devuelve un true si esta limpio
bool piso::isFloorClean(uint x, uint y) 
{
	if ((x < w) && (y < h))
	{
		return !baldosa[x + y * w];
	}
	
}
//******************************************************************

//*********************  cleanTile  ********************************
void piso::cleanTile(uint x, uint y)
{
	if ((x < w) && (y < h))
	{
		baldosa[x + y * w] = true;
	}
}
//******************************************************************

//*********************  countCleanTiles  **************************
uint piso::countCleanTiles(void)
{
	uint baldosasLimpias = 0;
	for (uint i = 0; i < h; i++)
	{
		for (uint j = 0; j < w; j++)
		{
			if (isFloorClean(j, i))
			{
				baldosasLimpias++;
			}
		}
	}
	return baldosasLimpias;
}
//******************************************************************

//***********************  destroy  ********************************
void piso::destroy()
{
	free(baldosa);
}
//******************************************************************