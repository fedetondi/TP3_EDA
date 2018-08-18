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
bool piso::isDirty(uint x, uint y)
{
	if ((x < w) && (y < h))
	{
		return baldosa[x + y * w];
	}
}
//******************************************************************

//**********************  isFloorClean******************************
bool piso::isFloorClean(uint x, uint y) // deveulve false si esta sucio, true si esta limpio
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