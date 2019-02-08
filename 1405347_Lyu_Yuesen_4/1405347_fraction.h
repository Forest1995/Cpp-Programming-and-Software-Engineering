//Header file ¡°Fraction.h¡± 
#ifndef FRACTION 
#define FRACTION 
class Fraction          //define a class of fraction
{
protected:
	int top; // Numerator
	int bottom; // Denominator
public:
	Fraction();                        //declare a default constrcutor
	Fraction(int a, int b = 1);        //declare a normal constructor
	Fraction add(Fraction a);          //declare function add,subtract, multiple and divide
	Fraction subtract(Fraction a);
	Fraction multiple(Fraction a);
	Fraction divide(Fraction a);
	void compare(Fraction a);         //declare compare function
	void input1();                    //declare input and output function
	void input2();
	void output();
	void reduction(Fraction &Fnum);   //declare a reduction function
	int find(int m, int n);           //declare a function that finds most common divisor of two integers
	int detectillegalvalue();         //declare a member function for detecting illegal inputs
};
#endif