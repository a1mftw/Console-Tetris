#pragma once
#include <iostream>

#include "windows.h"


class Console
{
public:
	Console();
	~Console();
	void cls();
	void changeColor(int colour);
	void changePos(short y, short x);
	void setPos();

private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consolePos = {0,0};
};

