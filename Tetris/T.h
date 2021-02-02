#pragma once
#include "Block.h"
class T :
	public Block
{
public:
	T();
	T(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext);
	void Rotate();
	void Draw();
	~T();
};

