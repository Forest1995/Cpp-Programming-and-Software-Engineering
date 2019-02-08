
// Define a class called Season that is an abstract data type for a season
// input:an integer number or three letters
// output:a current season and next season
// Author : lyu yuesen
#include<iostream>              // include information about standard library iostream
using namespace std;
class season {                  //define a class season
private:
	int number;                 //define an integer representing season
public:
	season();                               //declare a default constcrtor
	season(char x, char y, char z);         //declare a normal constructor
	season(int a);                          //declare another normal constructor
	void input1();                          //declare an input function
	char input2();                          //declare another input function
	void output();                          //declare a display function
	season next();                          //declare  a member function that returns the next season as a value of type Season
};
season::season() {                           //definition of default constructor
	number = 0; 
}
season::season(char x, char y, char z) {      //definition of normal constructor
	number = 0;              
	if (x == 's'&&y == 'p'&&z == 'r')         //let the season represented by integer
		number = 1;
	else if (x == 's'&&y == 'u'&&z == 'm')
		number = 2;
	else if (x == 'a'&&y == 'u'&&z == 't')
		number = 3;
	else if (x == 'w'&&y == 'i'&&z == 'n')
		number = 4;
	else
		number = 0;
}
season::season(int a) {             //definition of another constructor
	number = a;
}
void season::input1() {              //definition of input function
	cin >> number;                   //get the integer directly
}
char season::input2() {              //definition of another input function
	char a;                          //get the first character one by one
	cin >> a;
	return a;
}
void season::output() {             //definition of the display function
	if (number == 1)                //display the season based on the integer
		cout << "Spring";
	else if (number == 2)
		cout << "Summer";
	else if (number == 3)
		cout << "Autumn";
	else if (number == 4)
		cout << "Winter";
	else
		cout << "Error";
}
season season::next() {          //definition of the function that returns the next season as a value of type Season
	if (number < 4)              //let the integer plus one 
		number = number + 1;
	else if (number == 4)
		number = 1;
	else
		number = 0;
	return number;
}

int main() {
	for (;;) {
		char a, b, c;                          //declare variables
		int m;
		season S1, S2, S3;
		cout << "which type ?   1 for integer   2 for first three letters";//let user choose the type they want to input
		cin >> m;
		if (m == 1) {
			S1.input1();                      //use S1 as season type and use the member function input1
			cout << "The season is ";
			S1.output();                      //display the season
			cout << endl;
			S2 = S1.next();                   //S2 gets the value of next season
			cout << "The next season is ";
			S2.output();                      //display next season
			cout << endl;
		}
		else if (m == 2) {
			a = S1.input2();           //get the first three letters one by one
			b = S1.input2();
			c = S1.input2();
			season S3(a, b, c);          //set the season 
			cout << "The season is ";
			S3.output();              // display the season
			cout << endl;
			S2 = S3.next();           //S2 gets the value of next season
			cout << "The next season is ";
			S2.output();                //display next season
			cout << endl;
		}
		else
			;
	}
		return 0;
	

}
