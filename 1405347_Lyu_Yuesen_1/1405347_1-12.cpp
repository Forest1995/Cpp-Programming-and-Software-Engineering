#include <iostream>           // include information about standard library iostream
#include<string>              // include information about standard library string
using namespace std;
int main() {
	string StudentNumber;       // declare four string objects StudentNumber, FirstName, LastName , Str
	string FirstName;
	string LastName;
	string Str;
	cout << "Enter your student ID number:" ; //ask user to input student number
	cin >> StudentNumber;                     //store the input as object StudentNumber
	cout << "Enter your full name:";          //ask user to input full name
	cin >> FirstName >> LastName;             //store the fisrtname as object FirstName and the lastname as variable LastName, because space is considered the end of input 
	Str = StudentNumber + ", " + FirstName +" "+ LastName;//add all the information to a new string
	cout << "Your are " << Str << endl;        //display the result
	
	
}