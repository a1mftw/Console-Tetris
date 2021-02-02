#include "pch.h"
#include "Game.h"


using namespace std;
Console console;

Game::Game()
{
	for (int row = arenaStart; row < arenaSize; row++) {
		for (int col = arenaStart; col < arenaLength; col++) {
			if (row == arenaStart || col == arenaStart || row == arenaSize-1 || col == arenaLength-1)
			{
				playingfield[row][col] = arenaColor;
			}
		}
	}
}


Game::~Game()
{
	
}

void Game::newGame()
{
	console.cls();
	cout << " #######  #######  #######  ######   ####### #######\n";
	cout << "    #     #           #     #     #     #    #      \n";
	cout << "    #     #           #     #     #     #    #      \n";
	cout << "    #     #####       #     ######      #    #######\n";
	cout << "    #     #           #     #   #       #          #\n";
	cout << "    #     #           #     #    #      #          #\n";
	cout << "    #     #######     #     #     #  ####### #######\n";
	cout << "\n\nPress any key to start the game\n";
	_getch();
	console.cls();
}

void Game::gameOver()
{
	console.cls();
	cout << " #####     #    #     # ####### ####### #     # ####### ######\n";
	cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
	cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
	cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
	cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
	cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
	cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
	console.changeColor(WHITE_ON_BLACK);
	cout << "\n Your final score was: " << score;
	interpreter.writeHighscore(score);
	cout << "\n\nPress any key\n";
	_getch();
	console.cls();
	
}

void Game::gameLoop()
{
	
	while (!gameover)
	{

		if (_kbhit())
		{
			userInput();
		}

		if (time < gameSpeed)
		{
			time++;
		}
		else
		{
			Update();
			time = 0;
		}
	}
}

void Game::userInput()
{
		char key;

		key = _getch();

		switch (key)
		{
		case 'd':
			if (!checkColision())
			{
				if (currentBlock != nullptr)
				{
					currentBlock->PotentialTopLeft.Y++;

					if (!checkColision())
					{
						currentBlock->TopLeft = currentBlock->PotentialTopLeft;
					}
					else
					{
						currentBlock->PotentialTopLeft.Y--;
					}
				}
				break;
		case 'a':
			if (currentBlock != nullptr)
			{
				currentBlock->PotentialTopLeft.Y--;

				if (!checkColision())
				{
					currentBlock->TopLeft = currentBlock->PotentialTopLeft;
				}
				else
				{
					currentBlock->PotentialTopLeft.Y++;
				}
			}
			break;
		case 's':
			if (!checkColision())
			{
				if (currentBlock != nullptr)
				{
					currentBlock->PotentialTopLeft.X++;

					if (!checkColision())
					{
						currentBlock->TopLeft = currentBlock->PotentialTopLeft;
					}
					else
					{
						currentBlock->PotentialTopLeft.X--;
					}
				}
			}
			break;
		case ' ':
			rotateBlock();
			break;
			}
		}
}

void Game::Update()
{
	if (!checkColision())
	{
		moveBlock();
		Draw();
	}
	else
	{
		destroyBlock();
		clearLine();
		makeBlock();
		Draw();
		if (checkColision())
		{
			gameover = true;
		}	
	}	
}

void Game::Draw()
{
	for (int row = arenaStart; row < arenaSize; row++) {
		for (int col = arenaStart; col < arenaLength; col++) {
			if (playingfield[row][col]== arenaColor)
			{
				console.changeColor(BLACK_ON_WHITE);
				console.changePos(col, row);
				console.setPos();
				cout <<" ";
				console.changeColor(RED_ON_BLACK);

			}
			else if (playingfield[row][col] == blueTetrisColor)
			{
				console.changeColor(BLACK_ON_BLUE);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
				console.changeColor(RED_ON_BLACK);

			}
			else if (playingfield[row][col] == greenTetrisColor)
			{
				console.changeColor(BLACK_ON_GREEN);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
				console.changeColor(RED_ON_BLACK);

			}
			else if (playingfield[row][col] == redTetrisColor)
			{
				console.changeColor(BLACK_ON_RED);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
				console.changeColor(RED_ON_BLACK);

			}
			else if (playingfield[row][col] == purpleTetrisColor)
			{
				console.changeColor(BLACK_ON_PURPLE);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
				console.changeColor(RED_ON_BLACK);

			}
			else if (playingfield[row][col] == yellowTetrisColor)
			{
				console.changeColor(BLACK_ON_YELLOW);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
				console.changeColor(RED_ON_BLACK);

			}
			else
			{
				console.changeColor(RED_ON_BLACK);
				console.changePos(col, row);
				console.setPos();
				cout << " ";
			}
			
		}
		cout << endl;
	}

	currentBlock = nextBlock.front();
	for (int row = arenaStart; row < currentBlock->shape.size(); row++) {
		for (int col = arenaStart; col < currentBlock->shape[row].size(); col++) {
			if (nextBlock.front()->shape[row][col] != arenaEmpty) {
				
				console.changePos(row+currentBlock->TopLeft.Y,col+currentBlock->TopLeft.X);
				console.setPos();
				cout << "#";			
			}
		}
	}

	interpreter.getControlLine();
	//interpreter.scorestream.seekg(0, ios::beg);
	interpreter.controlStream >> controlPosY >> controlPosX;
	console.changeColor(WHITE_ON_BLACK);
	console.changePos(controlPosY, controlPosX);
	console.setPos();
	cout << "Controls:";
	interpreter.controlStream >> controlPosY >> controlPosX;
	console.changePos(controlPosY, controlPosX);
	console.setPos();
	cout << "Press A or D to move left or right";
	interpreter.controlStream >> controlPosY >> controlPosX;
	console.changePos(controlPosY, controlPosX);
	console.setPos();
	cout << "Press S to make the piece fall faster";
	interpreter.controlStream >> controlPosY >> controlPosX;
	console.changePos(controlPosY, controlPosX);
	console.setPos();
	cout << "Press Space to rotate the piece";
	interpreter.controlStream >> controlPosY >> controlPosX;
	console.changePos(controlPosY, controlPosX);
	console.setPos();
	cout << "Highscore: " << score;
	
}

void Game::makeBlock()
{
	nextBlock.push(interpreter.createBlock());
	
}

void Game::destroyBlock()
{

	if (currentBlock != nullptr)
	{
		for (int row = arenaStart; row < currentBlock->shape.size(); row++) {
			for (int col = arenaStart; col < currentBlock->shape[row].size(); col++) {
				if (currentBlock->shape[row][col]!= arenaEmpty)
				{
					playingfield[col + currentBlock->TopLeft.X][row + currentBlock->TopLeft.Y] = currentBlock->shape[row][col];
				}
			}
		}

		currentBlock = nullptr;
		nextBlock.pop();
	}

}

void Game::moveBlock()
{
	currentBlock->PotentialTopLeft.X++;
	currentBlock->TopLeft = currentBlock->PotentialTopLeft;
}

bool Game::checkColision()
{
	bool flag=false;
	if (currentBlock != nullptr)
	{
		for (int row = arenaStart; row < currentBlock->shape.size(); row++) {
			for (int col = arenaStart; col < currentBlock->shape[row].size(); col++) {
				if (currentBlock->shape[row][col] != arenaEmpty) {
					if (col+currentBlock->PotentialTopLeft.X>=playingfield.size()-2) {
						return flag = true;
					}
					else if (playingfield[col + currentBlock->PotentialTopLeft.X+1][row + currentBlock->PotentialTopLeft.Y] != arenaEmpty)
					{
						return flag = true;
					}
					else
					{
						flag = false;
					}
					
				}
			}
		}
	}
	else
	{
		return true;
	}
	return flag;
}

bool Game::rotateBlock()
{
	bool flag = false;
	currentBlock->rotation++;
	if (currentBlock->rotation==4)
	{
		currentBlock->rotation = 0;
	}
	currentBlock->Rotate();

	for (int row = arenaStart; row < currentBlock->potentialShape.size(); row++) {
		for (int col = arenaStart; col < currentBlock->potentialShape[row].size(); col++) {
			if (currentBlock->potentialShape[row][col] != arenaEmpty) {
				if (!(col + currentBlock->PotentialTopLeft.X >= playingfield.size() - 2))
					if (!(playingfield[col + currentBlock->PotentialTopLeft.X + 1][row + currentBlock->PotentialTopLeft.Y] != arenaEmpty))
						flag = false;
					else
					{
						return true;
					}
				else
				{
					return true;
				}
			}
		}
	}

	if (!flag)
	{
		currentBlock->shape = currentBlock->potentialShape;
	}
}

void Game::clearLine()
{
	
	for (int col = playFieldSize; col > arenaStart; col--) {
		counter = 0;
		for (int row = 1; row <= playingfield[col].size()-2; row++) {
			if (playingfield[col][row] != arenaEmpty)
			{
				counter++;
				if (counter == fullline)
				{
					score += pointsPerLine;
					for (; col > 1; col--) {
						for (row = 1; row < playingfield[col].size()-2; row++)
						{
							playingfield[col][row] = playingfield[col - 1][row];
						}
					}
					clearLine();
				}
			}
		}
	}


}


