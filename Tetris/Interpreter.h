#pragma once
#include <sstream>
#include "File.h"
#include "Block.h"
#include "Console.h"
#include <random>
#include "Bar.h"
#include "Square.h"
#include "T.h"
#include "L.h"
#include "Dog.h"

using namespace std;

class Interpreter
{
private:
	stringstream ss;
	File file;
	string type, text;
	unsigned row, column, colour;
	enum Shapes
	{
		Barshape,
		Squareshape,
		Dogshape,
		Lshape,
		Tshape
	};



public:
	stringstream controlStream;
	Interpreter();
	~Interpreter();
	void getControlLine();
	void getTestLine();
	void writeHighscore(int highscore);
	void interpret(int fileName);
	Block * createBlock();
	unsigned int randomBlock();
	
};

