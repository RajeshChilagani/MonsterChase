// MonsterChase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

using std::cin;
using std::cout;
class NameClass {
public:

	char* Name = NULL;
	char* TempName = NULL;
	char inputCharacter;
	int count = 0;
	int posX, posY;
	void Names()
	{
		do
		{
			inputCharacter = cin.get();
			if (inputCharacter != '\n')
			{
				count++;
				TempName = (char*)realloc(Name, count * sizeof(char));
				if (TempName != NULL)
				{

					TempName[count - 1] = inputCharacter;
					Name = TempName;
				}
				else {
					free(Name);
					free(TempName);
					exit(1);
				}
			}

		} while (inputCharacter != '\n');
	}
	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << Name[i];
		}
	}

};

int main()
{
	cout << "How Many monsters to start:";
	int numberOfMonsters;
	cin >> numberOfMonsters;
	while (!cin)
	{
		cout << "Bad Input try again \n";
		cin.clear(); // to clear the cin error state
		cin.ignore(1000, '\n'); // ignore characters in input buffer unitl /n
		cout << "How Many monsters to start:";
		cin >> numberOfMonsters;
		
	}
	cin.ignore();
	NameClass *m = new NameClass[numberOfMonsters];
	for (int i = 0; i < numberOfMonsters; i++)
	{
		cout << "enter name of monster"<<i<<":";
		m[i].Names();		
	}
	cout << "Enter player name:";
	// Player
	NameClass *p = new NameClass();
	p->Names();
	for (int i = 0; i< numberOfMonsters; i++)
	{
		m[i].print();
	}
	p->print();
	_getch();
}



