#include<iostream>
#include"fraction.h"
using namespace std;

class iFraction : public Fraction {        //subclass iFraction publicly inherited from base Fraction
	friend Fraction convertF(iFraction a);  //declare a freiend function which can convert mixed fractions to improper fractions
private:
	int m;               
public:
	iFraction();                          //default constructor 
	iFraction(int a, int b, int c);      //normal constructor
	~iFraction() {};                     //destructor
	void convert();                   
	void display();
	void input();
	void reduction(); 
	//these four are member functions which have different responsibilities
};


//convert mixed fractions to improper fractions
Fraction convertF(iFraction a) {
	int top, bottom;
	if (a.m >= 0||(a.top<0&&a.m<0))
	{
		top = a.m*a.bottom + a.top;
		bottom = a.bottom;
		a.m = 0;
		return Fraction(top, bottom);
	}
	else {
		top = -(-a.m*a.bottom + a.top);
		bottom = a.bottom;
		a.m = 0;
		return Fraction(top, bottom);
	}
}

//definition of default constructor
iFraction::iFraction() {
	m = 0;
	top = 0;
	bottom = 0;
}

//definition of normal constructor
iFraction::iFraction(int a, int b, int c) {
	m = a;
	top = b;
	bottom = c;
}

// converts improper fractions to mixed fractions
void iFraction::convert() {
	int temp = top / bottom;
	m = m + temp;
	top = top - temp*bottom;
}

//display the fraction based on its numerator and denominator
void iFraction::display() {
	if (m == 0) {
		reduction();
		output();
	}
	else if (top == bottom) {
		m = m + 1;
		top = 0;
		cout << m << endl;
	}
	else if (top < bottom) {
		cout << m << " ";
		reduction();
		output();
	}
	else {
		convert();
		cout << m << " ";
		reduction();
		output();
	}
}

//definition of input function
void iFraction::input() {
	cout << "Please enter the integer part:";
	m = detectillegalvalue();
	input1();
}

//definition of reduction function
void iFraction::reduction() {   

	if (bottom<0)                //if the bottom is less than zero, reverse it
	{
		top = -top;
		bottom = -bottom;
	}
	int f = find(abs(top), bottom); //find the most common divisor of two integers
	top = top / f;          //divide the most common divisor
	bottom = bottom / f;
}

int main() {
	for (;;) {
		iFraction A; Fraction B;
		A.input();
		cout << "The mixed fractions is ";
		A.display();
		B = convertF(A);                //convert mixed fraction to improper fraction
		cout << "It is converted to improper fraction ";
		B.output();
	}
}