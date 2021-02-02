#include "pch.h"
#include "Bar.h"


Bar::Bar()
{
	shape.push_back(vector<int>{ 2, 2, 2, 2 });
}

Bar::Bar(unsigned filerow, unsigned filecolumn, unsigned filecolour, string filetext)
{
	row = filerow;
	column = filecolumn;
	colour = filecolour;
	text = filetext;
}

void Bar::Rotate()
{
	potentialShape.clear();

	switch (rotation)
	{
	case 0:
		potentialShape.push_back(vector<int>{ 2, 2, 2, 2});
		break;
	case 1:
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		break;
	case 2:
		potentialShape.push_back(vector<int>{ 2, 2, 2, 2});
		break;
	case 3:
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		potentialShape.push_back(vector<int>{2});
		break;
	default:
		break;
	}
}

void Bar::Draw()
{
	console.changeColor(colour);
	console.changePos(column, row);
	console.setPos();
	std::cout << text << text << text << text;
}


Bar::~Bar()
{
}
