/*
NAME: Evan Miller
Assignment: Lab 2
Sources: geeksforgeks.org
*/

#include <iostream>

using namespace std;

int modular(long long base, long long exp, long long mod);


int main()
{
	cout << " Evan Miller\nLab 2\nCS251" << endl;
	
	for(int i = 0; i < 4; i++)
	{
	long long a, pow, mod;
	cout << "Please enter a number: " << flush;
	cin >> a;
	
	cout << "\nWhat power do you want " << a << " taken to? " << flush;
	cin >> pow;

	cout << "\n What is the modulo? " << flush;
	cin >> mod;

	cout << "\nThank you...computing..." << endl;

	cout << "\nThe residue is: " << modular(a,pow,mod) << endl;
	}	
	return 0;
}

int modular(long long base, long long exp, long long mod)
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
