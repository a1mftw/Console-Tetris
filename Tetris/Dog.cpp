#include "pch.h"
#include "Dog.h"


Dog::Dog()
{
	shape.push_back(vector<int>{ 3, 3, 0 });
	shape.push_back(vector<int>{ 0, 3, 3 });
}

void Dog::Rotate()
{
	potentialShape.clear();

	switch (rotation)
	{
	case 0:
		potentialShape.push_back(vector<int>{ 3, 3, 0 });
		potentialShape.push_back(vector<int>{ 0, 3, 3 });
		break;
	case 1:
		
		potentialShape.push_back(vector<int>{0, 3});
		potentialShape.push_back(vector<int>{3, 3});
		potentialShape.push_back(vector<int>{3, 0});
		break;
	case 2:
		potentialShape.push_back(vector<int>{ 3, 3, 0 });
		potentialShape.push_back(vector<int>{ 0, 3, 3 });
		break;
	case 3:
		potentialShape.push_back(vector<int>{0, 3});
		potentialShape.push_back(vector<int>{3, 3});
		potentialShape.push_back(vector<int>{3, 0});
		break;
	default:
		break;
	}
}


Dog::~Dog()
{
}
