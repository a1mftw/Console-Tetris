#pragma once
#include "conio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "FileNames.h"

using namespace std;

class File
{
private:
	fstream file;
	string fileLine;
	string allFileLines;
	string highScoreFilePath = {"highscore.txt"};
	string blockFilePath = {"block.txt"};



public:
	File();
	~File();
	bool checkFileState();
	bool checkEOF();
	string readLine(int fileName);
	void writeLine(int fileName,stringstream &ssWrite);
	void closeFile();


};

