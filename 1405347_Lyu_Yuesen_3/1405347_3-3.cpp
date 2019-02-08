// Write a function to search a character sequence pointed by a pointer (called ¡°obj¡±), in another character sequence (called ¡°source¡±). 
// input:several characters, denoting elements in two arrays 
// output:the found character
// Author : lyu yuesen
#include<iostream>              // include information about standard library iostream
#include<string>                // include information about standard library string
using namespace std;
char *findC(char const *source, char const *obj); //declare function findC with return type of char*
int main() {
	for (;;) {
		string s1, s2;      //delcare two strings
		char *pointer;      //declare a char pointer 
		cin >> s1;         //ask user to enter two strings
		cin >> s2;
		const char *p1 = s1.c_str();      //copy the content of s1 to char *p1
		const char *p2 = s2.c_str();      //copy the content of s2 to char *p2
		cout << "You are searching for " << p2 << " in " << p1 << endl;
		pointer = findC(p1, p2);     //search for the content of p2 in p1 by using funtion findC and give the return value to pointer
		if (pointer == NULL)         //display the results
			cout << "Not found" << endl;
		else
			cout << "The result is " << *pointer<<endl;
	}
	return 0;
}
char *findC(char const *source, char const *obj) { //definition of function findC
	char *p;            //declare a char pointer
	char x;             //decare a char variable
	int m = 0;
	int length1 = strlen(obj);   //get the length of *source and *obj
	int length2 = strlen(source);
	for (int i = 0; i < length1; i++) {       //compare the character in *obj with *source one by one
		for (int j = 0; j < length2; j++) {
			if (*(obj + i) == *(source + j)) {  // if the two characters are same, add one to m 
				m = m + 1;
				if (m == 1) {     //if m==1, let the pointer points to that character and stop comparing *(obj+i)
					x = source[j];
					p = &x;
					break;
				}
				else if ((m != 1) && (*(obj + i - 1) == *(source + j - 1))) {   //if m£¡=1 and the former characters of current character of both sequences are equal,stop comparing *(obj+i)
					 break;
				}
				else                         // for other cases, return NULL pointer
					return NULL;
			}
			else if (j == length2 - 1) {     //if the character has compared to the final character of source and did not find any same character, return NULL pointer
				return NULL;
			}
			else        // for other case, do nothing and continue the circulation
				; 
		}
	}
	return p;   //return the pointer;
	}



