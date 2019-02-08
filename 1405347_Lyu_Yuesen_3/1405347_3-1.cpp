// Design a new class to represent a date 
// input:two intergers, denoting the year and the date and the 3-letter abbreviation of the month 
// output:the date
// Author : lyu yuesen
#include<iostream>            // include information about standard library iostream
#include<string>              // include information about standard library string
using namespace std;
class Date {                  // define a class Date
private:
	int year;                          
	int date;
	string month;
	int m;            //define an integer representing month
public:
	Date();                               //declare a default constcrtor
	Date(int x, string y, int z);         //declare a normal constructor
	~Date() {};                           //declare a destructor
	void input();                         //declare an input function
	void output();                        //declare a display function
	void operator = (Date a);             //opeater overloading
	bool operator > (Date a);
	bool operator < (Date a);
	bool operator == (Date a);
	void operator ++();
};
Date::Date() {                   //definition of default constructor
	year = 0;
	date = 1;
	month = "Jan";
	m = 1;
}
Date::Date(int x, string y, int z) {          //definition of normal constructor
	year = x;                                
	month = y;
	date = z;
	if ((month == "JAN") || (month == "Jan"))   //let m represent the month
		m = 1;
	else if ((month == "FEB") || (month == "Feb"))
		m = 2;
	else if ((month == "MAR") || (month == "Mar"))
		m = 3;
	else if ((month == "APR") || (month == "Apr"))
		m = 4;
	else if ((month == "MAY") || (month == "May"))
		m = 5;
	else if ((month == "JUN") || (month == "Jun"))
		m = 6;
	else if ((month == "JUL") || (month == "Jul"))
		m = 7;
	else if ((month == "AUG") || (month == "Aug"))
		m = 8;
	else if ((month == "SEP") || (month == "Sep"))
		m = 9;
	else if ((month == "OCT") || (month == "Oct"))
		m = 10;
	else if ((month == "NOV") || (month == "Nov"))
		m = 11;
	else if ((month == "DEC") || (month == "Dec"))
		m = 12;
	else
		m = 0;
}
void Date::input() {                                  //definition of input function
	cout << "Please enter the year" << endl;     
	cin >> year;                                       //get the year, month and date
	cout<< "Please enter the month" << endl;         
	cin >> month;
	cout << "Please enter the date" << endl;
	cin >> date;
	if ((month == "JAN") || (month == "Jan"))      //set the value of m based on the month
		m = 1;
	else if ((month == "FEB")||(month=="Feb"))
		m = 2;
	else if ((month == "MAR") || (month == "Mar"))
		m = 3;
	else if ((month == "APR") || (month == "Apr"))
		m = 4;
	else if ((month == "MAY") || (month == "May"))
		m = 5;
	else if ((month == "JUN") || (month == "Jun"))
		m = 6;
	else if ((month == "JUL") || (month == "Jul"))
		m = 7;
	else if ((month == "AUG") || (month == "Aug"))
		m = 8;
	else if ((month == "SEP") || (month == "Sep"))
		m = 9;
	else if ((month == "OCT") || (month == "Oct"))
		m = 10;
	else if ((month == "NOV") || (month == "Nov"))
		m = 11;
	else if ((month == "DEC") || (month == "Dec"))
		m = 12;
	else
		m = 0;
}
void Date::output() {                                  //definition of input function
	if (m == 1)                                        //display the result based on year,month and date
		cout << year << "-Jan-" << date << endl;
	else if (m == 2)
		cout << year << "-Feb-" << date << endl;
	else if (m == 3)
		cout << year << "-Mar-" << date << endl;
	else if (m == 4)
		cout << year << "-Apr-" << date << endl;
	else if (m == 5)
		cout << year << "-May-" << date << endl;
	else if (m == 6)
		cout << year << "-Jun-" << date << endl;
	else if (m == 7)
		cout << year << "-Jul-" << date << endl;
	else if (m == 8)
		cout << year << "-Aug-" << date << endl;
	else if (m == 9)
		cout << year << "-Sep-" << date << endl;
	else if (m == 10)
		cout << year << "-Oct-" << date << endl;
	else if (m == 11)
		cout << year << "-Nov-" << date << endl;
	else if (m == 12)
		cout << year << "-Dec-" << date << endl;
	else
		cout << "Wrong" <<endl;

}
void Date::operator =(Date a) {      //definition of the operator = overloading
	year = a.year;                   //give the year, month,date and m of a to object who called the function
	month = a.month;
	date = a.date;
	m = a.m;
}
bool Date::operator >(Date a) {     //definition of the operator > overloading
	bool temp;                      //compare the year first ,and then the month and date.
	if (year > a.year)
		temp = 1;
	else if ((year == a.year) && (m > a.m))
		temp = 1;
	else if ((year == a.year) && (m == a.m) && (date > a.date))
		temp = 1;
	else temp = 0;
	return temp;
}
bool Date::operator <(Date a) {          //definition of the operator < overloading
	bool temp;                             //compare the year first ,and then the month and date.
	if (year < a.year)
		temp = 1;
	else if ((year == a.year) && (m < a.m))
		temp = 1;
	else if ((year == a.year) && (m == a.m) && (date < a.date))
		temp = 1;
	else temp = 0;
	return temp;
}
bool Date::operator ==(Date a) {         //definition of the operator == overloading
	bool temp;
	if ((year == a.year) && (m == a.m) && (date == a.date))   //compare the year, month and date
		temp = 1;
	else
		temp = 0;
	return temp;
}
void Date::operator ++() {              //definition of the operator ++ overloading
	if (m == 2)                         //for February, there are 28 days. add one to date if date is less than 28
		if (date < 28)
			date = date + 1;
		else if (date == 28) {          //if date is equal to 28, let date become 1 and add one to month
			date = 1; m = 3;
		}
		else {
			date = 1, m = 1;
		}
	else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10))//for JAN,MAR,MAY,JUL,AUG,OCT,there are 31 days. add one to date if date is less than 31
		if (date < 31)
			date = date + 1;
		else if (date == 31)            //if date is equal to 31, let date become 1 and add one to month
		{
			date = 1; m = m + 1;
		}
		else {
			date = 1, m = 1;
		}
	else if((m == 4) || (m == 6) || (m == 9) || (m == 11) ) // for APR, JUN,SEP, VOV, there are 30 days.add one to date if date is less than 30
		if (date < 30)
			date = date + 1;
		else if (date == 30)          //if date is equal to 30, let date become 1 and add one to month
		{
			date = 1; m = m + 1;
		}
		else {
			date = 1, m = 1;
		}
	else if((m==12))                //for December, if date is less than 31, add one to date
		if (date < 31)
			date = date + 1;
		else if (date == 31)       //if date is equal to 31, let date and month become 1,and add one to year
		{
			date = 1; m = 1; year = year + 1;
		}
		else {
			date = 1, m = 1;
		}
	else {
		year = 0;
		m = 1;
		date = 1;
	}
}
int main() {
	for (;;) {                                      
		Date a, b, c, d;                               // declare a,b,c,d of class Date
		cout << "Please enter the date A" << endl;     //ask user to enter the Date A
		a.input();
		a.output();
		cout << "Please enter the date B" << endl;     //ask user to enter the Date B
		b.input();
		b.output();
		c = a;                                         //give the date of a to c
		d = b;                                         //give the date of b to d
		cout << "The date A is";
		c.output();                                    //display the date of c
		cout << "The date B is";
		d.output();                                    //display the date of d
		if (a > b)                                     //compare the two dates and give the results
			cout << "The date A is bigger" << endl;
		else if (a < b)
			cout << "The date B is bigger" << endl;
		else if (a == b)
			cout << "The two dates are equal" << endl;
		else
			cout << "Wrong" << endl;
		++a;                                            //add one day to date A
		++b;                                            //add one day to date B
		cout << "The next date of date A is";           //display the result
		a.output();                                     
		cout << "The next date of date B is";
		b.output();
	}
	return 0;
}