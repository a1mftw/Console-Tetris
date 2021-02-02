#pragma once
#include "Block.h"
class Bar :
	public Block
{
public:
	Bar();
	Bar(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext);
	void Rotate();
	void Draw();
	~Bar();
};

