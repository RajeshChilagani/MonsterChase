// MonsterChase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

using std::cin;
using std::cout;
class GameObject {
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
	void setPositions(int x,int y)
	{
		posX = x;
		posY = y;
	}
	void getPositions()
	{
		
		print();
		cout << " is at [" << posX << "," << posY << "]\n";
	}
	void AImovement()
	{
		posX+= rand() % +400 - 200;
		posY+= rand() % +400 - 200;
	}
	void AIName()
	{
		char c = rand() % +26 + 'a';
		char d = rand() % +26 + 'a';
		char e = rand() % +26 + 'a';
		Name = new char[3] {c,d,e};
		count = 3;
	}
	
};

int main()
{
	int AddorDelInd = 5;
	cout << "How Many Monsters Do You Want In The Game:";
	int numberOfMonsters;
	cin >> numberOfMonsters;
	while (!cin)
	{
		cout << "Bad Input try again \n";
		cin.clear(); 
		cin.ignore(1000, '\n');
		cout << "How Many Monsters Do You Want In The Game:";
		cin >> numberOfMonsters;
		
	}
	cin.ignore();

	//Monsters
	GameObject *m = new GameObject[numberOfMonsters];
	for (int i = 0; i < numberOfMonsters; i++)
	{
		cout << "Enter The Name Of The Monster"<<i+1<<":";
		m[i].Names();
		m[i].setPositions(rand()%+200-100+i, rand() % +200-100+i);
		
	}

	// Player
	cout << "Enter The Player Name:";
	GameObject *p = new GameObject();
	p->Names();
	p->setPositions(0,0);
	for (int i = 0; i < numberOfMonsters; i++)
	{
		m[i].getPositions();
	}
	p->getPositions();

	// GameLoop 
	char keyBoardInput;
	do {
		cout << "Press A to move LEFT Press D to move RIGHT Press W to move UP Press S to move DOWN Q to QUIT\n";
		keyBoardInput = _getch();
		switch (keyBoardInput)
		{
		case 'a':
			p->posX -= 1;
			for (int i = 0; i < numberOfMonsters; i++)
			{
				m[i].getPositions();
			}
			p->getPositions();
			break;
		case 'd':
			p->posX += 1;
			for (int i = 0; i < numberOfMonsters; i++)
			{
				m[i].getPositions();
			}
			p->getPositions();
			break;
		case 'w':
			p->posY += 1;
			for (int i = 0; i < numberOfMonsters; i++)
			{
				m[i].getPositions();
			}
			p->getPositions();
			break;
		case 's':
			p->posY -= 1;
			for (int i = 0; i < numberOfMonsters; i++)
			{
				m[i].getPositions();
			}
			p->getPositions();
			break;
		case 'q':
			exit(1);
		default:
			for (int i = 0; i < numberOfMonsters; i++)
			{
				m[i].getPositions();
			}
			p->getPositions();
			break;
		}
		for (int i = 0; i < numberOfMonsters; i++)
		{
			m[i].AImovement();
		}
		GameObject* t;
		if (AddorDelInd==0)
		{
			numberOfMonsters -= 1;
			t = (GameObject*)realloc(m, numberOfMonsters* (sizeof(GameObject)));
			for (int i = 0; i < numberOfMonsters; i++)
			{
				t[i] = m[i];
			}
			m = t;
			cout << "One Monster Was Deleted\n";
			AddorDelInd = 5;
			
		}
		if(m == NULL || AddorDelInd== 4)
		{
			numberOfMonsters += 1;
			t = (GameObject*)realloc(m, numberOfMonsters* (sizeof(GameObject)));
			for (int i = 0; i < numberOfMonsters-1; i++)
			{
				t[i] = m[i];
			}
			cout << "Adding New Monster\n";
			t[numberOfMonsters - 1].AIName();
			t[numberOfMonsters - 1].setPositions(rand() % +200 - 100, rand() % +200 - 100);
			m = t;
			
		}
		AddorDelInd--;
		if (m == NULL)
		{
			cout << "All Monsters Are Dead GameOver\n";
			p->getPositions();
		}
	} while (m!=NULL);
	
	_getch();
}




