// Design a new class to represent a fraction 
// input: two integers representing the numerator and denominator of a fraction
// output:the results of addition, subtraction, multiplication, division and the comparison between two fractions
// Author : lyu yuesen
#include<iostream>
using namespace std;
class Fraction          //define a class of fraction
{
private:
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
};
Fraction::Fraction() {            //definition of default constructor
	top = 1;
	bottom = 1;
}
Fraction::Fraction(int a, int b) {  //definition of normal constructor
	top = a;
	bottom = b;
}
Fraction Fraction::add(Fraction a) {    //definition of add function
	Fraction temp;
	temp.top = top * a.bottom + a.top *bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);                       //return the result of type fraction after adding
}
Fraction Fraction::subtract(Fraction a) {   //definition of subtract function  
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);     //return the result of type fraction after subtracting
}
Fraction Fraction::multiple(Fraction a) {    //definition of multiple function
	Fraction temp;
	temp.top = top * a.top;
	temp.bottom = bottom * a.bottom;
	reduction(temp);
	return(temp);         //return the result of type fraction after multipling
	
}
Fraction Fraction::divide(Fraction a) {      //definition of divide function
	Fraction temp;
	temp.top = top * a.bottom;
	temp.bottom = bottom * a.top;
	reduction(temp);
	return(temp);     //return the result of type fraction after dividing
}
void Fraction::compare( Fraction a) {          //definition of compare function
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	if (temp.top>0)
		cout <<top<<"/"<<bottom<< " is bigger"<<endl;
	else if (temp.top<0)
		cout << a.top << "/" << a.bottom << " is bigger" << endl;
	else
		cout << "They are equal" << endl;
}
void Fraction::input1() {                       //definition of input1 function
	cout << "Please enter the Numerator: ";
	cin >> top;
	cout << "Please enter the Denominator: ";
	cin >> bottom;
}
void Fraction::input2() {                        //definition of input2 function
	cout << "Please enter the Numerator: ";
	cin >> top;
}
void Fraction::output() {                       //definition of output function
	cout << top << "/" << bottom << endl;
}
int Fraction::find(int m, int n) {               //definition of find function
	if (n == 0) return m;                      //if n is not equal to zero, keep finding
	else return find(n, m%n);
}
void Fraction::reduction(Fraction &Fnum) {        //definition of reduction function

	if (Fnum.bottom<0)                //if the bottom is less than zero, reverse it
	{
		Fnum.top = -Fnum.top;
		Fnum.bottom = -Fnum.bottom;
	}
	int f = find(abs(Fnum.top), Fnum.bottom); //find the most common divisor of two integers
	Fnum.top = Fnum.top / f;          //divide the most common divisor
	Fnum.bottom = Fnum.bottom / f;
}
int main() {
	for (;;) {
		int a, b;           //declare variables
		Fraction F1, F2, result1, result2, result3, result4;
		cout << "enter the first number       1 for fraction       2 for integer"; //let user choose the type
		cin >> a;
		if (a == 1)                  //enter the first number
			F1.input1();          
		else
			F1.input2();
		cout << "enter the second number      1 for fraction       2 for integer";
		cin >> b;
		if (b == 1)                 //enter the second number
			F2.input1();
		else
			F2.input2();
		result1=F1.add(F2);                        //make calculations and display the results
		cout << "The addition result is ";
		result1.output();
		result2 = F1.subtract(F2);
		cout << "The subtraction result is ";
		result2.output();
		result3 = F1.multiple(F2);
		cout << "The multiplication result is ";
		result3.output();
		result4 = F1.divide(F2);
		cout << "The division result is ";
		result4.output();
		F1.compare( F2);
	}
}
