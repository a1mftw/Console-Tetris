#pragma once
#include "Block.h"
class L :
	public Block
{
public:
	L();
	L(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext);
	void Rotate();
	void Draw();
	~L();
};

