/*
NAME: Evan Miller
ASSIGNMENT: Lab 1
CLASS: CS251
SOURCES:
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string setA, setB;
	cout << "Evan Miller \nLab 1 \nCS251 " << endl;

	cout << "Input the items in set A, separated by spaces.\nWhen you are done hit return. " << endl;
	fflush(stdin);
	getline(cin, setA, ' ');
	//need to loop over cin to set all items in array of strings
	cout << "\nItems in setA: " << setA << endl;

	return 0;
}
