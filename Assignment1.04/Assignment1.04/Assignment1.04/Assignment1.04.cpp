// Assignment1.04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

int main()
{
 const char * strings[] = {
		"Thus",
		"is",
		"a",
		NULL
	};
 
 char * p = nullptr;
 char * temp = nullptr;
 int i = 0;
 int mainsize = 0;
while (strings[i] != '\0')
{
	int size = 0;
	const char* tempstring = strings[i];
	while (tempstring[size] != '\0')
	{
		mainsize++;
	
		temp = (char*)realloc(p, mainsize * sizeof(char));
		if (temp != nullptr)
		{
			temp[mainsize - 1] = tempstring[size];
			p = temp;
		}
		size++;
	}
	mainsize++;
	temp = (char*)realloc(p, mainsize * sizeof(char));
	if (strings[i + 1] == '\0')
	{
		
		if (temp != nullptr)
		{
			temp[mainsize - 1] = '.';
			p = temp;
		}
	}
	else
	{
		if (temp != nullptr)
		{
			temp[mainsize - 1] = ' ';
			p = temp;
		}

	}
	
	i++;
}
//for (int i = 0; i < mainsize; i++)
//{
//	std::cout << p[i];
//}
std::cout << p;

 
}

