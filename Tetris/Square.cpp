#include "pch.h"
#include <vector>
#include "Square.h"


Square::Square()
{
	shape.push_back(vector<int>{ 6, 6 });
	shape.push_back(vector<int>{ 6, 6 });
}

Square::Square(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext)
{
	row = filerow;
	column = filecolumn;
	colour = filecolour;
	text = filetext;
}

void Square::Draw()
{
	console.changeColor(colour);
	console.changePos(column, row);
	console.setPos();
	std::cout << text << text;
	console.changePos(column, row + 1);
	console.setPos();
	std::cout << text << text;
}


Square::~Square()
{
}
