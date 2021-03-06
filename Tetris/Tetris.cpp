// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Console.h"
#include "conio.h"
#include "Interpreter.h"


using namespace std;

int main()
{
	
	
	Interpreter interpreter;
	Console console;
	int choice = -1;
	do
	{
		Game game;
		short choice;

		cout << " _____________________________________________________\n";
		cout << "|                                                     |\n";
		cout << "|                                                     |\n";
		//cout << "|Press 1 for the test case                            |\n";
		cout << "|Press 1 for a tetris game                            |\n";
		cout << "|                                                     |\n";
		cout << "|                                                     |\n";
		cout << "|Press 0 to Exit                                      |\n";
		cout << "|_____________________________________________________|\n";
		cin >> choice;
		while (!cin)
		{
			cout << "\nPlease input a correct number\n";
			cin.clear();
			cin.ignore();
			cin >> choice;

		}

		switch (choice)
		{	
		case 1:
			
			game.newGame();
			game.gameLoop();
			game.gameOver();
			
				
			break;

		case 0:
			exit(0);
			break;

		default:
			cout << "\n\n Wrong number\n";
			system("pause");
			break;
		}

	} while (choice != 0);
}

