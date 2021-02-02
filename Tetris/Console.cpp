#include "pch.h"
#include "Console.h"
#include "Colours.h"


Console::Console()
{
}


Console::~Console()
{
}

void Console::cls()
{
		COORD topLeft = { 0, 0 };	
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;
		GetConsoleScreenBufferInfo(hConsole, &screen);
		FillConsoleOutputCharacterA(
			hConsole, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		FillConsoleOutputAttribute(
			hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);

		changePos(0,0),
		setPos();
}

void Console::changeColor(int colour)
{
	SetConsoleTextAttribute(hConsole, colour);
}

void Console::changePos(short x, short y)
{
	consolePos = { x , y };
}

void Console::setPos()
{
	SetConsoleCursorPosition(hConsole, consolePos);
}
