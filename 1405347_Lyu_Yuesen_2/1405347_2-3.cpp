// Design a composite class represents complex numbers whose real and imaginary parts are Fractions.
// input: two fractions representing the real part and imaginary part of a complex number
// output:the results of addition, subtraction, multiplication, division between two complex numbers
// Author : lyu yuesen
#include<iostream>
using namespace std;
class Fraction                // include the class Fraction
{
private:
	int top; // Numerator
	int bottom; // Denominator
public:
	Fraction();
	Fraction(int a, int b = 1);
	Fraction add(Fraction a);
	Fraction subtract(Fraction a);
	Fraction multiple(Fraction a);
	Fraction divide(Fraction a);
	void compare(Fraction a);
	void input1();
	void input2();
	void output();
	void reduction(Fraction &Fnum);
	int find(int m, int n);
};
Fraction::Fraction() {
	top = 1;
	bottom = 1;
}
Fraction::Fraction(int a, int b) {
	top = a;
	bottom = b;
}
Fraction Fraction::add(Fraction a) {
	Fraction temp;
	temp.top = top * a.bottom + a.top *bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);
}
Fraction Fraction::subtract(Fraction a) {
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	temp.bottom = a.bottom * bottom;
	reduction(temp);
	return(temp);
}
Fraction Fraction::multiple(Fraction a) {
	Fraction temp;
	temp.top = top * a.top;
	temp.bottom = bottom * a.bottom;
	reduction(temp);
	return(temp);

}
Fraction Fraction::divide(Fraction a) {
	Fraction temp;
	temp.top = top * a.bottom;
	temp.bottom = bottom * a.top;
	reduction(temp);
	return(temp);
}
void Fraction::compare(Fraction a) {
	Fraction temp;
	temp.top = top * a.bottom - a.top * bottom;
	if (temp.top>0)
		cout << top << "/" << bottom << " is bigger" << endl;
	else if (temp.top<0)
		cout << a.top << "/" << a.bottom << " is bigger" << endl;
	else
		cout << "They are equal" << endl;
}
void Fraction::input1() {
	cout << "Please enter the Numerator: ";
	cin >> top;
	cout << "Please enter the Denominator: ";
	cin >> bottom;
}
void Fraction::input2() {
	cout << "Please enter the Numerator: ";
	cin >> top;
}
void Fraction::output() {
	cout << top << "/" << bottom;
}
int Fraction::find(int m, int n) {
	if (n == 0) return m;
	else return find(n, m%n);
}
void Fraction::reduction(Fraction &Fnum) {

	if (Fnum.bottom < 0)
	{
		Fnum.top = -Fnum.top;
		Fnum.bottom = -Fnum.bottom;
	}
	int f = find(abs(Fnum.top), Fnum.bottom);
	Fnum.top = Fnum.top / f;
	Fnum.bottom = Fnum.bottom / f;
}

class complex                      //define a class complex
{             
private:
	Fraction real;               //declare two variables of typr fraction representing real part and imaginary part
	Fraction imag;
public:
	complex();                         //declare a default constrcutor
	complex(Fraction f1, Fraction f2);  //declare a normal constructor
	complex add(complex a);             // //declare function add,substract, multiple and divide
	complex subtract(complex a);
	complex multiple(complex a);
	complex divide(complex a);
	void input();                       //declare input and output function
	void output();
};
complex::complex(){                   //definition of default constructor
}
complex::complex(Fraction f1, Fraction f2) :real(f1), imag(f2) {  // definition of normal constructor
	real = f1;
	imag = f2;
}
complex complex::add(complex a) {        //definition of add function
	complex temp;
	temp.real = real.add(a.real);
	temp.imag = imag.add(a.imag);
	return temp;                          //return the result of type complex after adding
}
complex complex::subtract(complex a) {     //definition of substract function  
	complex temp;
	temp.real = real.subtract(a.real);
	temp.imag = imag.subtract(a.imag);
	return temp;                          //return the result of type complex after substracting
}
complex complex::multiple(complex a) {     //definition of multiple function
	complex temp; Fraction temp1, temp2, temp3, temp4;
	temp1 = real.multiple(a.real);    //use functions of class fraction to do calculations
	temp2= imag.multiple(a.imag);
	temp.real = temp1.subtract(temp2);
	temp3 = real.multiple(a.imag);
	temp4 = imag.multiple(a.real);
	temp.imag = temp3.add(temp4);
	return temp;                 //return the result of type complex after multipling
}
complex complex::divide(complex a) {   //definition of divide function
	complex temp; Fraction temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
	temp1 = real.multiple(a.real); // use functions of class fraction to do calculations
	temp2 = imag.multiple(a.imag);            
	temp3 = a.real.multiple(a.real);
	temp4 = a.imag.multiple(a.imag);
	temp5 = temp1.add(temp2);
	temp6 = temp3.add(temp4);
	temp.real = temp5.divide(temp6);
	temp7= imag.multiple(a.real);
	temp8= real.multiple(a.imag);
	temp9 = temp7.subtract(temp8);
	temp.imag = temp9.divide(temp6);
	return temp;                //return the result of type complex after dividing
}
void complex::input() {            //definition of input function
	cout << "Please enter the real part" << endl;
	real.input1();         //use input function of class fraction
	cout << "Please enter the imaginary part" << endl;
	imag.input1();
}
void complex::output() {      //definition of output function
	real.output();             //use output function of class fraction
	cout << "+j ";
	imag.output();
	cout << endl;
}
int main() {
	for (;;) {
		complex c1, c2, result1, result2, result3, result4;   //declare variables
		cout << "Please enter the first complex number" << endl;//enter the first complex number
		c1.input();
		cout << "The first complex number is ";
		c1.output();                                           //display the first number
		cout << "Please enter the second complex number" << endl;//enter the second complex number
		c2.input();
		cout << "The second complex number is ";
		c2.output();                                         //display the second number
		result1 = c1.add(c2);                          //make calculations and dispaly the results
		cout << "The addition result is ";
		result1.output();
		result2 = c1.subtract(c2);
		cout << "The subrraction result is ";
		result2.output();
		result3 = c1.multiple(c2);
		cout << "The multiplication result is ";
		result3.output();
		result4 = c1.divide(c2);
		cout << "The division result is ";
		result4.output();
	}
	return 0;
}