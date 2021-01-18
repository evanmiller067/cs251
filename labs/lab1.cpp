/*
NAME: Evan Miller
ASSIGNMENT: Lab 1
CLASS: CS251
SOURCES:http://www.cplusplus.com/reference/sstream/istringstream/istringstream/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string setA, setB;
	cout << "Evan Miller \nLab 1 \nCS251 " << endl;
	
	//get setA from user, store in vector
	cout << "Input the items in set A, separated by spaces.\nWhen you are done hit return. " << endl;
	fflush(stdin);
	getline(cin, setA);
	istringstream ssA(setA);
	vector<string> vectorA;
	for(string s;ssA>>s;)
	{
		vectorA.push_back(s);
	}
	
	//get setB
	cout << "\nInput the items in set B, separated by spaces. \nWhen you are done hit return. " << endl;
	fflush(stdin);
	getline(cin, setB);
	istringstream ssB(setB);
	vector<string> vectorB;
	for(string s; ssB>>s;)
	{
		vectorB.push_back(s);
	}

	// test to see vector items
	cout << "items in VectorA: " << endl;
	int n = vectorA.size();	
	for(int i = 0; i < n; i++)
	{
		cout << vectorA[i] << endl;
	}
	
	cout << "Items in VectorB: " << endl;
	int b = vectorB.size();
	for(int i = 0; i < b; i++)
	{
		cout << vectorB[i] << endl;
	}
	//end of vector test

	return 0;
}
