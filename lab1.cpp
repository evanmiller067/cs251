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
#include <algorithm>

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
	//output set a
	cout << "The following is a list of the items in set A: " << endl;
	cout << "A = { " << flush;
	int a = vectorA.size();	
	for(auto & it : vectorA)
	{
		cout << it << " ";
	}
	cout << "} \nSet A contains " << a << " items." << endl;

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
	//output set  B
	cout << "The following is a list of the items in set B: " << endl;
	cout << "B = { " << flush;
	int b = vectorB.size();
	for(auto & it : vectorB)
	{
		cout << it << " ";
	}
	cout << "} \nSet B contains " << b << " items." << endl;

// A intersect B
	int interCard = 0;	
	cout << "\nA intersect B contains the following:\n{ ";
	//intersect function
	for(size_t i = 0; i < a; ++i)
	{
		vector<string>::iterator it = find(vectorB.begin(), vectorB.end(), vectorA[i]);
		if(it != vectorB.end())
		{
			cout << vectorA[i] << " ";
			interCard++;
		}
	}
	cout << "} \nThe cardinality of the intersection is " << interCard << endl;

//A U B
	
	cout << "\nA U B contains the following: \n{ ";

	vector<string> unionA = vectorA;
	vector<string> unionB = vectorB;
	vector<string> unionC;
	sort(unionA.begin(), unionA.end());
	sort(unionB.begin(), unionB.end());
	
	merge(unionA.begin(), unionA.end(), unionB.begin(), unionB.end(), std::back_inserter(unionC));	

	vector<string>::iterator pte = unique(unionC.begin(), unionC.end());
	unionC.erase(pte, unionC.end());	
	
	for(auto & it : unionC)
	{
		cout << it << " ";
	}

	cout << "} \nThe cardinality of the union is " << unionC.size() << endl;	

//A - B
	cout << "\nA - B = { " << flush;
	vector<string> difference; 
	std::set_difference(unionA.begin(), unionA.end(), unionB.begin(), unionB.end(), std::inserter(difference, difference.begin()));
	for(auto i : difference)
	{
		cout << i << " ";
	}
	cout << " }\nThe cardinality is " << difference.size() << endl;

//B - A
	cout << "\nB - A = { " << flush;
	vector<string> differenceB; 
	std::set_difference(unionB.begin(), unionB.end(), unionA.begin(), unionA.end(), std::inserter(differenceB, differenceB.begin()));
	for(auto i : differenceB)
	{
		cout << i << " ";
	}
	
	cout << "}\nThe cardinality is " << differenceB.size() << endl;

//A X B
	int axbCard = a * b;
	cout << "\nThe cardinality of A X B is " << axbCard << endl;
	cout << "A X B contains { " << flush;
	for(int i = 0; i < a; ++i)
	{
		for(int j = 0; j < b; ++j)
		{
			cout << "(" << vectorA[i] << ", " << vectorB[j] << ")";
		}
	}
//powerset
	int powerCard = a*b;
	cout << "\nThe cardinality of the power set of the cross product is " << (1LL <<  powerCard) << endl;

	return 0;
}
