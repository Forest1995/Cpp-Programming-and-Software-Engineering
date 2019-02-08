#include<iostream>                  // include information about standard library iostream
using namespace std;
int main() {
	int AScore[3][2] = { 2,1,1,4,2,2 };          //declare four two-dimension arrays which contains the scores of each team
	int BScore[3][2] = { 3,1,4,2,1,2 };         
	int CScore[3][2] = { 2,2,2,4,1,1 };
	int DScore[3][2] = { 4,1,1,3,1,1 };
	int APoints = 0; int BPoints = 0; int CPoints = 0; int DPoints = 0;   //declare four int variables which represent the points of each team
	int AGoalDfiierence=0; int BGoalDfiierence = 0; int CGoalDfiierence = 0; int DGoalDfiierence = 0;//declare four int variables which represent the goal difference of each team
	int AGoals = 0; int BGoals = 0; int CGoals = 0; int DGoals = 0;//declare four int variables which represent the goals of each team
	for (int i = 0;i<3; i++) {                               //use for loop to calculate the points ,goal difference and goals of each team
		AGoalDfiierence += AScore[i][0] - AScore[i][1];      
		AGoals += AScore[i][0];                        
		if (AScore[i][0]>AScore[i][1])             //in a football match, if won for 3 points, tie for 1 point, lose for no point.
			APoints += 3;
		else if (AScore[i][0] == AScore[i][1])
			APoints += 1;
		else
			APoints += 0;
	}
	for (int i = 0; i<3; i++) {
		BGoalDfiierence += BScore[i][0] - BScore[i][1];
		BGoals += BScore[i][0];
		if (BScore[i][0]>BScore[i][1])
			BPoints += 3;
		else if (BScore[i][0] == BScore[i][1])
			BPoints += 1;
		else
			BPoints += 0;
	}
	for (int i = 0; i<3; i++) {
		CGoalDfiierence += CScore[i][0] - CScore[i][1];
		CGoals += CScore[i][0];
		if (CScore[i][0]>CScore[i][1])
			CPoints += 3;
		else if (BScore[i][0] == CScore[i][1])
			CPoints += 1;
		else
			CPoints += 0;
	}
	for (int i = 0; i<3; i++) {
		DGoalDfiierence += DScore[i][0] - DScore[i][1];
		DGoals += DScore[i][0];
		if (DScore[i][0]>DScore[i][1])
			DPoints += 3;
		else if (DScore[i][0] == DScore[i][1])
			DPoints += 1;
		else
			DPoints += 0;
	}
	cout << "APoints: " << APoints << endl << "Bpoints: " << BPoints << endl;      
	cout <<"Cpoints: "<< CPoints <<endl<<"Dpoints: "<< DPoints << endl;
	cout << "AGoalDfiierence: " << AGoalDfiierence << endl << "BGoalDfiierence: " << BGoalDfiierence << endl;
	cout << "CGoalDfiierence: " << CGoalDfiierence << endl << "DGoalDfiierence: " << DGoalDfiierence << endl;
	cout << "AGoals: " << AGoals << endl << "BGoals: " << BGoals << endl;
	cout << "CGoals: " << CGoals << endl << "DGoals: " << DGoals << endl; //display the points, goal difference and goals of each team
	int SortPoints[4] = { APoints ,BPoints,CPoints,DPoints };    //declare four arrays which respectively contain name, points ,goal difference and goals of each team
	char ABCD[4] = { 'A','B','C','D' };
	int SortGoalDfiierence[4] = { AGoalDfiierence, BGoalDfiierence, CGoalDfiierence, DGoalDfiierence };
	int SortGoals[4] = { AGoals, BGoals, CGoals, DGoals };
	for (int i = 0; i < 4; i++)             //use two for loops to conduct bubble sort                  
	{
		for (int j = 0; j < 3; j++)
		{
			if (SortPoints[j] < SortPoints[j + 1])      //if the former number is smaller than the latter, exchange them
			{
				int temp = SortPoints[j];
				SortPoints[j] = SortPoints[j + 1];
				SortPoints[j + 1] = temp;
				int m = SortGoalDfiierence[i];
				SortGoalDfiierence[j] = SortGoalDfiierence[j + 1];
				SortGoalDfiierence[j + 1] = m;
				int n = SortGoals[j];
				SortGoals[j] = SortGoals[j + 1];
				SortGoals[j+1] = n;
				char k = ABCD[j];
				ABCD[j] = ABCD[j + 1];
				ABCD[j + 1] = k;
			}
			if (SortPoints[j] == SortPoints[j + 1])             //if equal,check the goal difference
			{
				if (SortGoalDfiierence[j] < SortGoalDfiierence[j + 1])//if the former number is smaller than the latter, exchange them
				{
					int temp = SortPoints[j];
					SortPoints[j] = SortPoints[j + 1];
					SortPoints[j + 1] = temp;
					int m = SortGoalDfiierence[i];
					SortGoalDfiierence[j] = SortGoalDfiierence[j + 1];
					SortGoalDfiierence[j + 1] = m;
					int n = SortGoals[j];
					SortGoals[j] = SortGoals[j + 1];
					SortGoals[j + 1] = n;
					char k = ABCD[j];
					ABCD[j] = ABCD[j + 1];
					ABCD[j + 1] = k;
				}
				if (SortGoalDfiierence[j] == SortGoalDfiierence[j + 1]) //if equal,check the goals
				{
					if (SortGoals[j] < SortGoals[j + 1])              //if the former number is smaller than the latter, exchange them
					{
						int temp = SortPoints[j];                 
						SortPoints[j] = SortPoints[j + 1];
						SortPoints[j + 1] = temp;
						int m = SortGoalDfiierence[i];
						SortGoalDfiierence[j] = SortGoalDfiierence[j + 1];
						SortGoalDfiierence[j + 1] = m;
						int n = SortGoals[j];
						SortGoals[j] = SortGoals[j + 1];
						SortGoals[j + 1] = n;
						char k = ABCD[j];
						ABCD[j] = ABCD[j + 1];
						ABCD[j + 1] = k;
					}
				}

			}
		}
	}
	cout <<"The rank of four teams are "<< ABCD[0] << ABCD[1] << ABCD[2] << ABCD[3];//display the rank of four teams
	
}