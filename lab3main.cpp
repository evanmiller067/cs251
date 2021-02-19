/*
NAME: EVAN MILLER
ASSIGNMENT: LAB 3
CLASS: CS251
SOURCES: cplusplus.com

Program: open .txt file using command line argument,
apply RSA cypher to numbers inside, 
find residues and decrypt message.
Cout Messaage.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//function to find residue
int modular(int base, long long exp, long long mod);


int main(int argc, char *argv[])
{
	cout << "\nEvan Miller \nCS251 \nLab 3" << endl;

	//read in string data, store in vector delim at spaces
	using isii = std::istream_iterator<string>;
	ifstream in{argv[1]};
	vector<string> numbers{isii{in}, isii{}};
	
	//cast string to long/int
	long long pq = stoll(numbers[2]);
	int d = stoll(numbers[5]);

	//erase the first five elements to prevent errors in decryption
	numbers.erase(numbers.begin(), numbers.begin()+6);

	//display vector
/*	cout << "File contents: ";
	for(auto i = numbers.begin(); i != numbers.end(); i++)
	{
		cout << *i << ", ";
	}
*/
	//convert string to long long
	vector<int> intnum;
	std::transform(numbers.begin(), numbers.end(), std::back_inserter(intnum),[] (const std::string& str) {return std::stoi(str); });
	
	//loop over mod function inputing each value as base
	for(auto & it : intnum)
	{
		int x = it;
		cout <<( char) modular(x, d, pq); //converted to ascii char by casting
	}
	cout << "\n" << endl;
return 0;
}
//mod function from lab 2 
int modular(int base,long long exp, long long  mod)
{
    int x = 1;
    int power = base % mod;

    for(int i = 0; i < sizeof(long long) * 8; i++)
    {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if(least_sig_bit)
        {
            x = (x*power) % mod;
        }
        power = (power * power) % mod;
    }
    return x;
}
