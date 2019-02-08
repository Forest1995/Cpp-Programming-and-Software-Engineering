// Write a program by using several points to fit a curve. The curve could be either linear or polynomial
// input: an integer reprsenting the choice
// output: the original points and the modifed points
// author: lyu yuesen

#include <iostream> 
#include <fstream>
#include <string>
#include<math.h>      //in the main function, pow() function is used 

using namespace std;

int CountLines(char *filename);         // declaration of self-defined functions
double SecondOrderDeterminant(double a1, double a2, double b1, double b2);
double ThirdOrderDeterminant(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3 );
int detectillegalvalue();

int main()
{
	//according to the requirements,variables are declared 
	string WholeLine;
	int choice, LINES;
	double a1 = 0;
	double a2 = 0;
	double a3 = 0;
	double b1 = 0;
	double b2 = 0;
	double b3 = 0;
	double c1 = 0;
	double c2 = 0;
	double c3 = 0;
	double d1 = 0;
	double d2 = 0;
	double d3 = 0;
	double a, b, c;
	double error = 0;
	LINES = CountLines("my_file.txt");    //here use the function to count the lines of my_file.txt

	//four allocated pointers are declared
	double *x = new double[LINES];
	double *y = new double[LINES];
	double *CLy= new double[LINES];
	double *CSy= new double[LINES];

	cout << "Here are the points in the my_file.txt:" << endl;
	cout << endl;
	ifstream fin("my_file.txt");             // open my_file.txt
	for (int i = 0; i<LINES; i++)
	{
		getline(fin, WholeLine);         //use the getline() function to get each line of my_file.txt file 
		cout << WholeLine << endl;       //output the whole line
	}
	cout << endl;
	system("pause");
	system("cls");
	fin.seekg(0, ios::beg);           //move the pointer to the beginning 
	//use eof() function to check whether the operator read the end of file
	//if the return value is zero, it means that operator does read the end of file
	for (int i = 0; fin.eof() == 0; i++)
	{
		fin >> x[i];
		fin >> y[i];           //store x and y respectively
	}
	fin.close();
	
	for (;;) {
		cout << "Enter 1, represent a straight line." << endl;
		cout << "Enter 2, represent a second order polynomial equation." << endl;
		cout << "please enter the integer:" << endl;
		choice = detectillegalvalue();
		if (choice == 1)      //if d=1 which means the user choose linear regression analysis 
		{
			ofstream fout("my_display.txt");              // create and open my_display.txt    
			for (int i = 0; i < LINES; i++) {      //use pow() function to calculate a1, a2, b1, b2,d1,d2, a and b according to the tips in the question 
				a1 += pow(x[i], 2);
				a2 += x[i];
				d1 += -(x[i] * y[i]);
				d2 += -y[i];
			}
			b1 = a2;
			b2 = LINES;
			a = SecondOrderDeterminant(b1, b2, d1, d2) / SecondOrderDeterminant(a1, a2, b1, b2);
			b = -SecondOrderDeterminant(a1, a2, d1, d2) / SecondOrderDeterminant(a1, a2, b1, b2);
			for (int k = 0; k < LINES; k++)
			{
				CLy[k] = a*x[k] + b;            //CLy is the modifed value
				error += abs(CLy[k] - y[k]);   
			}
			fout << "line" << endl;                               //display the information in screen and in file
			cout << "line" << endl;
			fout << "a=" << a << "\t" << "b=" << b << endl;      
			cout << "a=" << a << "\t" << "b=" << b << endl;
			for (int i = 0; i < LINES; i++)                       //output x, y and calculated y on the following lines
			{
				fout << x[i] << "\t" << y[i] << " \t" << CLy[i] << endl;
				cout << x[i] << "\t" << y[i] << "\t " << CLy[i] << endl;
			}
			fout << "ES=" << error << endl;
			cout << "ES=" << error << endl;
			cout << "The date is shown above and you could also obtain data infomation from the file named my_display.txt." << endl;
			fout.close();       			//close the file.
			delete[]x;
			delete[]y;
			delete[]CLy;
			delete[]CSy;
			// at last, all the allocated memory of pointers should be deleted
			return 0;
		}

		else if (choice == 2)       //if d=2, it is the ploynomial regression ayalysis
		{
			ofstream fout("my_display.txt");
			for (int i = 0; i < LINES; i++) {    //use a list of calculational formulas to calculated a1, a2, a3, b1, b2, b3, c1, c2, c3, a, b, and c
				a1 += pow(x[i], 4);
				a2 += pow(x[i], 3);
				a3 += pow(x[i], 2);
				b3 += x[i];
				d1 += -((pow(x[i], 2)*y[i]));
				d2 += -(x[i] * y[i]);
				d3 += -y[i];
			}
			b1 = a2;
			b2 = a3;
			c1 = a3;
			c2 = b3;
			c3 = LINES;
			a = -(ThirdOrderDeterminant(b1, b2, b3, c1, c2, c3, d1, d2, d3) / ThirdOrderDeterminant(a1, a2, a3, b1, b2, b3, c1, c2, c3));
			b = ThirdOrderDeterminant(a1, a2, a3, c1, c2, c3, d1, d2, d3) / ThirdOrderDeterminant(a1, a2, a3, b1, b2, b3, c1, c2, c3);
			c = -(ThirdOrderDeterminant(a1, a2, a3, b1, b2, b3, d1, d2, d3) / ThirdOrderDeterminant(a1, a2, a3, b1, b2, b3, c1, c2, c3));
			for (int k = 0; k < LINES; k++)
			{
				CSy[k] = a*pow(x[k], 2) + b*x[k] + c;       //store the claculated y into array CSy
				error += abs(CSy[k] - y[k]);
			}
			fout << "polynomial" << endl;                  //display the information in screen and in file
			cout << "polynomial" << endl;
			fout << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << endl;
			cout << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << endl;
			for (int i = 0; i < LINES; i++)                 //output x, y and calculated y on the following lines
			{
				fout << x[i] << "\t" << y[i] << "\t" << CSy[i] << endl;
				cout << x[i] << "\t" << y[i] << "\t" << CSy[i] << endl;
			}
			fout << "ES=" << error << endl;
			cout << "ES=" << error << endl;
			cout << "The date is shown above and you could also obtain data infomation from the file named my_display.txt." << endl;
			fout.close();    			//close the file.
			delete[]x;
			delete[]y;
			delete[]CLy;
			delete[]CSy;
			// at last, all the allocated memory of pointers should be deleted
			return 0;
		}

		else {                  //if user enter other numbers, ask them to enter again
			cout << "Not an availabe choice, plaese enter again" << endl;
		}
	}
}




 //Here is the defination of coutlline() function
int CountLines(char *filename)
{
	ifstream infile;     
	int n = 0;
	string temp;           //declare a string variable called temp
	infile.open(filename, ios::in);
	if (infile.fail())
	{
		infile.close();
		return 0;//there is nothing in the file,then, return 0 line
	}
	else
	{
		//using while() loop to read each line in the file and store it in string varibale temp
		while (getline(infile, temp))
		{
			n++;  //add one to n for counting lines
		}
		infile.close();
		return n;
	}
}

//definition of the second order determinant function
double SecondOrderDeterminant(double a1, double a2, double b1, double b2) {   
	double temp;
	temp = a1*b2 - a2*b1;
	return temp;
}


//definition of the third order determinant function
double ThirdOrderDeterminant(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3) {
	double temp;
	temp = a1*(b2*c3 - c2*b3) - b1*(a2*c3 - c2*a3) + c1*(a2*b3 - a3*b2);
	return temp;
}

//definition of the illegal input function
int detectillegalvalue(){
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