#pragma once
#include "Block.h"
class Square :
	public Block
{

private:
	
public:
	Square();
	Square(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext);
	void Draw();
	~Square();
};

