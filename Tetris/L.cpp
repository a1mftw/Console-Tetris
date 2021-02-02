#include "pch.h"
#include "L.h"


L::L()
{
	shape.push_back(vector<int>{ 0, 4 });
	shape.push_back(vector<int>{ 0, 4 });
	shape.push_back(vector<int>{ 4, 4 });
}

L::L(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext)
{
	row = filerow;
	column = filecolumn;
	colour = filecolour;
	text = filetext;
}

void L::Rotate()
{
	potentialShape.clear();

	switch (rotation)
	{
	case 0:
		potentialShape.push_back(vector<int>{ 0, 4 });
		potentialShape.push_back(vector<int>{ 0, 4 });
		potentialShape.push_back(vector<int>{ 4, 4 });
		break;
	case 1:
		potentialShape.push_back(vector<int>{ 4, 0, 0});
		potentialShape.push_back(vector<int>{ 4, 4, 4});
		
		break;
	case 2:
		potentialShape.push_back(vector<int>{ 4, 4});
		potentialShape.push_back(vector<int>{ 4, 0});
		potentialShape.push_back(vector<int>{ 4, 0});
		break;
	case 3:
		potentialShape.push_back(vector<int>{ 4, 4, 4});
		potentialShape.push_back(vector<int>{ 0, 0, 4});
		break;
	default:
		break;
	}
}

void L::Draw()
{
	console.changeColor(colour);
	console.changePos(column+2, row);
	console.setPos();
	std::cout << text;
	console.changePos(column+2, row + 1);
	console.setPos();
	std::cout << text;
	console.changePos(column+1, row + 1);
	console.setPos();
	std::cout << text;
	console.changePos(column, row + 1);
	console.setPos();
	std::cout << text;
}


L::~L()
{
}
