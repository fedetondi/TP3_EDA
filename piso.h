#ifndef PISO_H
#define PISO_H

#include "definitions.h"

typedef unsigned int uint;

class piso
{
	bool * baldosa;
	uint h;
	uint w;
	errType error;

	bool isFloorClean(uint x, uint y);

public:
	piso(uint hCount, uint wCount);
	bool isDirty(uint x, uint y);
	void cleanTile(uint x, uint y);
	uint countCleanTiles(void);
	void destroy();
	uint getH(void);
	uint getW(void);

};

#endif
