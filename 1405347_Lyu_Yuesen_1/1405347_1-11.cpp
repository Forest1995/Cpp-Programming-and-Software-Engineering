#include <iostream>             // include information about standard library iostream
#include <cstring>               // include information about standard library cstring
using namespace std;
int main() {
	char StudentNumber[50];         // declare five char variables StudentNumber, FirstName, LastName , Str,Comma
	char FirstName[50];
	char LastName[50];
	char Str[100];
	char Comma[5] = ", ";
	cout << "Enter your student ID number:";  //ask user to input student number
	cin >> StudentNumber;                     // store the input as variable StudentNumber
	cout << "Enter your full name:";          //ask user to input full name
	cin >> FirstName >> LastName;             //store the fisrtname as variable FirstName and the lastname as variable LastName, because space is considered the end of input
	strcpy(Str, StudentNumber);               //copy the characters from StudentNumber into Str
	strcat(Str, Comma);                       //attach characters from Comma to Str
	strcat(Str, FirstName);                   //attach characters from FirstName to Str
	strcat(Str, LastName);                    //attach characters from LastName to Str
	cout << "Your are " << Str << endl;       //display the results
}