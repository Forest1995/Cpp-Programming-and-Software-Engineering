#include <iostream>                   // include information about standard library iostream
using namespace std;
int main() {
	float GeorgeInvestment = 200;          //declare float variables GeorgeInvestment and PaulInvestment
	float PaulInvestment =200;
	int i = 0;
	for ( i = 0;  PaulInvestment<=GeorgeInvestment; i++)    //for loop to calculate the money until Paul 's is bigger than George.
	{ 
		GeorgeInvestment = 200 * 0.1 + GeorgeInvestment;
		PaulInvestment = PaulInvestment + PaulInvestment*0.05;
	}
	cout << "Paul's investment will exceed the value of George's investment in " << i << " years." << endl;
	cout << "Paul will have " << PaulInvestment << " dollars." << endl;
	cout << "George will have " << GeorgeInvestment << " dollars." << endl;           //display all the information
}