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
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; ++j)
		{
			if(vectorA[i] == vectorB[j])
			{
				cout << vectorA[i] << " ";
				++interCard;
				break;
			}
		}
	}
/*
	vector<string> v(10);
	vector<string>:: iterator it, st;
	int sizeN = sizeof(vectorA) / sizeof(vectorA[0]);
	sort(vectorA, vectorA + sizeN);
	sort(vectorB, vectorB + sizeN);

	it = set_intersection(vectorA, vectorA + sizeN, vectorB, vectorB + sizeN, v.begin());
	for (st = v.begin(); st != it; ++st)
	{
		cout << " " << *st;
	}
	cout << "} \nThe cardinality of the intersection is " << interCard << endl;
*/

//A U B
	int unionCard = a;
	cout << "\nA U B contains the following: \n{ ";

	int fin[25] = {0};
	for(int i = 0; i < a; ++i)
	{
		cout << vectorA[i] << " ";
		for(int j = 0; j < b; ++j)
		{
			if(vectorA[i] == vectorB[j])
			{
				fin[j] = i;
			}
		}
		for(int i = 0; i < b; ++i)
		{
			if(!fin[i])
			{
				cout << vectorB[i] << " ";
				++unionCard;
			}
		}
	}
	cout << "} \nThe cardinality of the union is " << unionCard << endl;	

//A - B
	int abCard = 0;
	cout << "\nA - B = { " << flush;
	for(int i = 0; i < a; ++i)
	{
		for(int j = 0; j < b; ++j)
		{
			if(vectorA[i] == vectorB[j])
			{
				break;
			}
			if(j == b)
			{
				cout << vectorA[i] << " ";
				++abCard;
			}
		}
	}
	cout << " }\nThe cardinality is " << abCard << endl;

//B - A
	int baCard = 0;
	cout << "\nB - A = { " << flush;
	for(int i = 0; i < b; ++i)
	{
		for(int j = 0; j < a; ++j)
		{
			if(vectorB[i] == vectorA[j])
			{
				break;
			}
			if(j == a)
			{
				cout << vectorB[i] << " ";
				++baCard;
			}
		}
	}
	cout << "}\nThe cardinality is " << baCard << endl;

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
