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
 
 char * pSentence = nullptr;
 int stringsLength = 0;
 int pSentenceSize = 0;
while (strings[stringsLength] != '\0')
{
	int size = 0;
	while (strings[stringsLength][size] != '\0')
	{
		pSentenceSize++;
		size++;
	}
	pSentenceSize++;
	stringsLength++;
}
pSentence = (char*)malloc(pSentenceSize+1 *sizeof(char));
stringsLength = 0;
pSentenceSize = 0;
while (strings[stringsLength] != '\0')
{
	int size = 0;
	while (strings[stringsLength][size] != '\0')
	{
		pSentence[pSentenceSize] = strings[stringsLength][size];
		pSentenceSize++;
		size++;
	}
	stringsLength++;
	if (strings[stringsLength] == '\0')
	{
		pSentence[pSentenceSize] = '.';
	}
	else
	{
		pSentence[pSentenceSize] = ' ';
	}
	
	pSentenceSize++;
	
}
pSentence[pSentenceSize] = '\0';
std::cout << pSentence;

free(pSentence);

_CrtDumpMemoryLeaks();
}

