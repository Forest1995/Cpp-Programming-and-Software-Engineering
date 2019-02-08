// Header file "fraction.cpp"
#include<iostream>
#include"fraction.h"
using namespace std;


//definition of default constructor
Fraction::Fraction() {            
	top = 1;
	bottom = 1;
}


//definition of normal constructor
Fraction::Fraction(int a, int b) { 
	top = a;
	bottom = b;
}


//definition of add function
Fraction Fraction::add(Fraction a) {    
	Fraction temp;
	temp.top = top * a.bottom + a.top *bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);                       //return the result of type fraction after adding
}


//definition of subtract function  
Fraction Fraction::subtract(Fraction a) {   
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);     //return the result of type fraction after subtracting
}


//definition of multiple function
Fraction Fraction::multiple(Fraction a) {   
	Fraction temp;
	temp.top = top * a.top;
	temp.bottom = bottom * a.bottom;
	reduction(temp);
	return(temp);         //return the result of type fraction after multipling
}


//definition of divide function
Fraction Fraction::divide(Fraction a) {     
	Fraction temp;
	temp.top = top * a.bottom;
	temp.bottom = bottom * a.top;
	reduction(temp);
	return(temp);     //return the result of type fraction after dividing
}


//definition of compare function
void Fraction::compare(Fraction a) {         
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	if (temp.top > 0)
		cout << top << "/" << bottom << " is bigger" << endl;
	else if (temp.top < 0)
		cout << a.top << "/" << a.bottom << " is bigger" << endl;
	else
		cout << "They are equal" << endl;
}


//definition of input1 function
void Fraction::input1() {                      
	cout << "Please enter the Numerator: ";
	top = detectillegalvalue();
	cout << "Please enter the Denominator: ";
	bottom = detectillegalvalue();
	if (bottom == 0) {
		cout << "the denominator can not be zero" << endl;
		input1();
	}
}


//definition of input2 function
void Fraction::input2() {                        
	cout << "Please enter the Numerator: ";
	cin >> top;
}
void Fraction::output() {                       //definition of output function
	cout << top << "/" << bottom << endl;
}


//definition of find function
int Fraction::find(int m, int n) {              
	if (n == 0) return m;                      //if n is not equal to zero, keep finding
	else return find(n, m%n);
}


//definition of reduction function
void Fraction::reduction(Fraction &Fnum) {       

	if (Fnum.bottom<0)                //if the bottom is less than zero, reverse it
	{
		Fnum.top = -Fnum.top;
		Fnum.bottom = -Fnum.bottom;
	}
	int f = find(abs(Fnum.top), Fnum.bottom); //find the most common divisor of two integers
	Fnum.top = Fnum.top / f;          //divide the most common divisor
	Fnum.bottom = Fnum.bottom / f;
}


// function for detecting illegal inputs
int Fraction::detectillegalvalue() {
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