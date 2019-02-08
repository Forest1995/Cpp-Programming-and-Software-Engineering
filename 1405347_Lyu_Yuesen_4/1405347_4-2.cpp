//=======================
//		main.cpp
//=======================

// main function for the RPG style game

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#include "swordsman.h"
#include"archer.h"
#include"mage.h"

//function for detecting illegal inputs
int detectillegalvalue() {                     
	int value;
	for (;;) {
		cin >> value;
		if (cin.fail())
		{
			cout << "illegal input, please enter again" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			return value;
	}
	return 0;
}

int main()
{
	bool flag;          //flag for restart the game
	do
	{
	string tempName;
	bool success=0;		//flag for storing whether operation is successful
	cout <<"Please input player's name: ";
	cin >>tempName;		// get player's name from keyboard input
	player *human;		// use pointer of base class, convenience for polymorphism
	player *enemy;      // use pointer of base class, convenience for polymorphism
	int tempJob;		// temp choice for job selection
	do
	{
		cout <<"Please choose a job: 1 Swordsman, 2 Archer, 3 Mage"<<endl;
		tempJob = detectillegalvalue();
		system("cls");		// clear the screen
		switch(tempJob)
		{
		case 1:
			human=new swordsman(1,tempName);	// create the character with user inputted name and job
			success=1;		// operation succeed
			break;
		case 2:
			human = new archer(1, tempName);	// create the character with user inputted name and job
			success = 1;		// operation succeed
			break;
		case 3:
			human = new mage(1, tempName);	// create the character with user inputted name and job
			success = 1;		// operation succeed
			break;
		default:
			break;				// In this case, success=0, character creation failed
		}
	}while(success!=1);		// so the loop will ask user to re-create a character

	int tempCom;			// temp command inputted by user
	int nOpp=0;				// the Nth opponent
    for (int i = 1; nOpp < 5; i += 2)	// i is opponent's level
		{
			nOpp++;
			system("cls");
			cout << "STAGE" << nOpp << endl;
			srand((unsigned)time(NULL));		// generating random seed based on system time
			int t = rand() % 3 + 1;             //generates a number no greater than 3
			
			//generate enemy of random profession
			if (t == 1) {                            
				cout << "Your opponent, a Level " << i << " Swordsman." << endl;
				system("pause");
				enemy = new swordsman(i, "Warrior");
			}
			else if (t == 2) {
				cout << "Your opponent, a Level " << i << " Archer." << endl;
				system("pause");
				enemy = new archer(i, "Shooter");
			}
			else {
				cout << "Your opponent, a Level " << i << " Mage." << endl;
				system("pause");
				enemy = new mage(i, "Wizard");
			}
				human->reFill();
				// get HP/MP refill before start fight
				while (!human->death() && !enemy->death())	// no died
				{
					success = 0;
					while (success != 1)
					{
						showinfo(*human, *enemy);				// show fighter's information
						cout << "Please give command: " << endl;
						cout << "1 Attack; 2 Special Attack; 3 Use Heal; 4 Use Magic Water; 0 Exit Game" << endl;
						tempCom = detectillegalvalue();
						switch (tempCom)
						{
						case 0:
							cout << "Are you sure to exit? Y/N" << endl;
							char temp;
							cin >> temp;
							if (temp == 'Y' || temp == 'y')
								return 0;
							else
								break;
						case 1:
							success = human->attack(*enemy);
							human->isLevelUp();
							enemy->isDead();
							break;
						case 2:
							success = human->specialatt(*enemy);
							human->isLevelUp();
							enemy->isDead();
							break;
						case 3:
							success = human->useHeal();
							break;
						case 4:
							success = human->useMW();
							break;
						default:
							break;
						}
					}
					if (!enemy->death())		// If AI still alive
						enemy->AI(*human);
					else							// AI died
					{
						cout << "YOU WIN" << endl;
						human->transfer(*enemy);		// player got all AI's items
					}
					if (human->death())
					{
						system("cls");
						cout << endl << setw(50) << "GAME OVER" << endl; //ask user whether they want to revive
						cout << "Do you want to revive?   'Y/N' " << endl;
						char x;
						cin >> x;
						if (x == 'Y' || x == 'y') {
							human->reFill();
							human->isDead();
						}			                    	// player is dead, program is getting to its end, what should we do here?
						else {
							system("pause");
							return 0;
						}
					}
				}
			}
		
	    // You win, program is getting to its end, what should we do here?
		system("cls");
		cout << "Congratulations! You defeated all opponents!!" << endl;
		cout << "Do you want to start again?  'Y/N' " << endl;            //ask user whether they want to restart
		char y;
		cin >> y;
		if (y == 'Y' || y == 'y') 
			flag = 1;
		else {
			system("pause");
			return 0;
		}
	}while (flag);
}
		

