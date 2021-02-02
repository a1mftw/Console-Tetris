#pragma once
#include "conio.h"
#include <iostream>
#include "Console.h"
#include <string>
#include <vector>


using namespace std;
class Block
{
protected:
	unsigned int colour;
	string text;
	unsigned column;
	unsigned row;
	Console console;

public:
	unsigned int rotation=0;
	Block();
	COORD TopLeft={1,4};
	COORD PotentialTopLeft = { TopLeft.X+1,TopLeft.Y };
	vector<vector<int>> potentialShape;
	vector<vector<int>> shape;
	virtual void Draw();
	virtual void Rotate();
	virtual ~Block();
};

