#pragma once
#include "Block.h"
#include <vector>
#include <queue>
#include "stdlib.h"
#include "Console.h"
#include <iostream>
#include "Colours.h"
#include "conio.h"
#include "Interpreter.h"

class Game
{
public:
	Game();
	~Game();
	
	void newGame();
	void gameOver();
	void gameLoop();
	void userInput();
	void Update();
	void Draw();
	void makeBlock();
	void destroyBlock();
	void moveBlock();
	bool checkColision();
	bool rotateBlock();
	void clearLine();

private:
	unsigned int score=0;
	unsigned int controlPosX = 0;
	unsigned int controlPosY = 0;
	unsigned int counter = 0;
	bool gameover = false;
	Block* currentBlock = nullptr;
	queue<Block *> nextBlock;
	vector<vector<int>> playingfield{ 18, vector<int>(12,0)};
	const unsigned int gameSpeed = 20000;
	Block block;
	Interpreter interpreter;
	size_t time = 0;
	stringstream highscorestream;
	const unsigned int pointsPerLine = 100;
	const unsigned int arenaEmpty = 0;
	const unsigned int arenaColor = 1;
	const unsigned int blueTetrisColor = 2;
	const unsigned int greenTetrisColor = 3;
	const unsigned int redTetrisColor = 4;
	const unsigned int purpleTetrisColor = 5;
	const unsigned int yellowTetrisColor = 6;
	const unsigned int arenaSize = 18;
	const unsigned int arenaLength = 12;
	const unsigned int playFieldSize = 16;
	const unsigned int arenaStart = 0;
	const unsigned int fullline = 10;

	
};

