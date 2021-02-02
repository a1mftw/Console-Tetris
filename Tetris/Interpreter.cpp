#include "pch.h"
#include "Interpreter.h"
#include "Tester.h"


Interpreter::Interpreter()
{
}


Interpreter::~Interpreter()
{
}

void Interpreter::getControlLine()
{
	
	controlStream << file.readLine(Controls);
}

void Interpreter::getTestLine()
{
	ss << file.readLine(Testing);
}

void Interpreter::writeHighscore(int highscore)
{
	ss << highscore;
	file.writeLine(Highscore,ss);
}

void Interpreter::interpret(int fileName)
{
	Block block;
	Console console;
	Tester tester;
	stringstream sscopy;
	string token;
	switch (fileName)
	{
	console.cls();
	case Testing:
			getTestLine();
			sscopy << ss.rdbuf();
			ss.seekg(0, ios::beg);
			tester.isReadyToTest();
			while (!ss.eof())
			{
				
				getline(ss, token, '\n');

				if (token=="")
				{
					break;
				}
				

				Block* p_Block = nullptr;
				sscopy >> type >> row >> column >> colour >> text;

				if (type == "SQUARE")
				{
					
					console.cls();
					p_Block = new Square(row, column, colour, text);
					p_Block->Draw();
 					tester.test(token);

				}
				if (type == "BAR")
				{
					
					console.cls();
					p_Block = new Bar(row, column, colour, text);
					p_Block->Draw();
					tester.test(token);
				}
				if (type == "L")
				{
					
					console.cls();
					p_Block = new L(row, column, colour, text);
					p_Block->Draw();
					tester.test(token);
				}
				if (type == "T")
				{
				
					console.cls();
					p_Block = new T(row, column, colour, text);
					p_Block->Draw();
					tester.test(token);

				}
				if (type == "TEXT")
				{
					
					console.cls();
					console.changeColor(colour);
					console.changePos(column, row);
					console.setPos();
					string fulltext = text;
					getline(sscopy, text, '\n');
					fulltext += text;
					std::cout << fulltext;
					tester.test(token);
				}
				console.changeColor(WHITEONBLACK);
				cout << "\n\n";
				_getch();
			
			}	
			ss.clear();
			ss.seekg(0, ios::beg);
		console.changeColor(7);
		console.changePos(25, 25);
		console.setPos();
		std::cout << "\n\n\nEnd of file press any key to exit";
		_getch();
		console.cls();
		
		break;

	case Controls:
		break;

	default:
		break;
	}
}

Block * Interpreter::createBlock()
{
	Block* p_Block = nullptr;
	switch (randomBlock())
	{
	case Barshape:
		p_Block = new Bar;
		break;
	case Squareshape:
		p_Block = new Square;
		break;
	case Dogshape:
		p_Block = new Dog;
		break;
	case Lshape:
		p_Block = new L;
		break;
	case Tshape:
		p_Block = new T;
		break;
	default:
		break;
	}

	return p_Block;
}

unsigned int Interpreter::randomBlock()
{
	random_device rd;
	mt19937 mt_rand{ rd() };
	uniform_int_distribution<int> uid{ 0,4 };
	unsigned int random_number = uid(mt_rand);
	return random_number;
}

