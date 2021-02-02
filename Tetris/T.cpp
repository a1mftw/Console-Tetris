#include "pch.h"
#include "T.h"


T::T()
{
	shape.push_back(vector<int>{ 5, 5, 5 });
	shape.push_back(vector<int>{ 0, 5, 0 });
}

T::T(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext)
{
	row = filerow;
	column = filecolumn;
	colour = filecolour;
	text = filetext;
}

void T::Rotate()
{
	potentialShape.clear();

	switch (rotation)
	{
	case 0:
		potentialShape.push_back(vector<int>{ 5, 5, 5 });
		potentialShape.push_back(vector<int>{ 0, 5, 0 });
		break;
	case 1:
		potentialShape.push_back(vector<int>{ 0, 5});
		potentialShape.push_back(vector<int>{ 5, 5});
		potentialShape.push_back(vector<int>{ 0, 5});
		break;
	case 2:
		potentialShape.push_back(vector<int>{ 0, 5, 0});
		potentialShape.push_back(vector<int>{ 5, 5, 5});
		break;
	case 3:
		potentialShape.push_back(vector<int>{ 5, 0});
		potentialShape.push_back(vector<int>{ 5, 5});
		potentialShape.push_back(vector<int>{ 5, 0});
		break;
	default:
		break;
	}
}

void T::Draw()
{
	console.changeColor(colour);
	console.changePos(column+1, row);
	console.setPos();
	std::cout << text;
	console.changePos(column , row+1);
	console.setPos();
	std::cout << text << text << text;
	
}


T::~T()
{
}
