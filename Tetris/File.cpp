#include "pch.h"
#include "File.h"


File::File()
{
}


File::~File()
{
}

bool File::checkFileState()
{
	if (file.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool File::checkEOF()
{
	if (file.eof())
	{
		return true;
		
	}
	else
	{
		return false;
	}

}

string File::readLine(int fileName)
{
	allFileLines = "";
	switch (fileName)
	{
	case Testing:
		file.open("Testing.txt");
		if (checkFileState())
		{
			
			while (!checkEOF()) {
				getline(file, fileLine);
				allFileLines += fileLine + '\n';
				
			}
			file.clear();
			file.seekg(0, ios::beg);
			closeFile();
			return allFileLines;
			
			
		}
		
		break;

	case Controls:
		file.open("Controls.txt");
		if (checkFileState())
		{
			while (!checkEOF()) {
				getline(file, fileLine);
				allFileLines += fileLine + '\n';

			}
			file.clear();
			file.seekg(0, ios::beg);
			closeFile();
			return allFileLines;
		}
		
		break;

	default:
	
		break;

		
	}
}

void File::writeLine(int fileName,stringstream &ssWrite)
{
	switch (fileName)
	{
	case Testing:
		file.open("Testing.txt");
		if (checkFileState())
		{
			file << ssWrite.str();
			closeFile();
		}
		break;

	case Highscore:
		file.open("highscore.txt", std::ios::app);
		if (checkFileState())
		{
			file << ssWrite.str()<<"\n";
			closeFile();
		}
		break;

	default:
		break;
	}
}


void File::closeFile()
{
	
	file.close();
}
