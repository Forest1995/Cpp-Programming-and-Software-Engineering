// Write a function that checks whether two vectors have the same elements, ignoring the order and multiplicities. 
// input:several intergers, denoting elements in the vector 
// output:the result of the comparison
// Author : lyu yuesen
#include<iostream>              // include information about standard library iostream
#include<vector>                // include information about standard library vector
using namespace std;
bool same_vec(vector<int> a, vector<int> b); //declare function same_vec with return type of bool
int main() {
	for (;;) {
		int a, b;
		cout << "Please enter the size of the first vector" << endl; //ask user to enter the size of first vector
		cin >> a;
		cout << "Please enter the elements one by one" << endl;     //ask user to enter the elements one by one
		vector<int>v1(a);
		for (int i = 0; i < a; i++) {
			cin >> v1[i];
		}
		cout << "The first vector is { ";     //  display the first vector
		for (int i = 0; i < a; i++) {
			cout << v1[i] << " ";
		}
		cout << "}" << endl;
		cout << "Please enter the size of the second vector" << endl;  //ask user to enter the size of second vector
		cin >> b;
		cout << "Please enter the elements one by one" << endl;       //ask user to enter the elements one by one
		vector<int>v2(b);
		for (int j = 0; j < b; j++) {
			cin >> v2[j];
		}
		cout << "The second vector is { ";                           //  display the second vector
		for (int j = 0; j < b; j++) {
			cout << v2[j] << " ";
		}
		cout << "}" << endl;
		if (same_vec(v1, v2))                        //compare the two vectors by using function same_vec, and display the results
			cout << "The two vectors are the same" << endl;
		else
			cout << "The two vectors are not the same" << endl;
	}
}
bool same_vec(vector<int> a, vector<int> b) {
	vector<int>m1(a.size());              //declare two vector variables of size of a and size of b
	vector<int>m2(b.size());
	int sum1 = 0; int sum2 = 0;         
	for (int i = 0; i < a.size(); i++) {   //compare the element in the first vector with the second vector one by one
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {            //if the two intergers are same, let the m1[i] be 1 and stop comparing a[i]
				m1[i] = 1; break;
			}
			else                              //if the two intergers are different, let the ith vector of m1 be 0 
			{
				m1[i] = 0;                
			}
		}
	}
	for (int i = 0; i < b.size(); i++) {       //compare the element in the second vector with the first vector one by one
		for (int j = 0; j < a.size(); j++) {
			if (b[i] == a[j]) {                //if the two intergers are same, let the m2[i] be 1 and stop comparing b[i]
				m2[i] = 1; break;
			}
			else                              //if the two intergers are different, let the ith vector of m2 be 0 
			{
				m2[i] = 0;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {      //let sum1 equal to the sum of elments of vector m1
		sum1 = sum1 + m1[i];
	}
	for (int j = 0; j < b.size(); j++) {      //let sum2 equal to the sum of elments of vector m2
		sum2 = sum2 + m2[j];
	}
	if ((sum1 == a.size())&&(sum2==b.size()))  //if sum1 is equal to size of a and sum2 is equal to size of b, the two vectors are same and return true
		return true;
	else                                     //if not, return false
		return false;
}