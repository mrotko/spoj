#include <iostream>
#include <string>
using namespace std;

bool checkBigLetter(char c)
{
	return c >= 'A' && c <= 'Z';
}

bool checkSmallLetter(char c)
{
	return c >= 'a' && c <= 'z';
}

bool checkNumber(char c)
{
	return c >= '0' && c <= '9';
}

bool checkSpecialChar(char c)
{
	if(checkNumber(c) || checkSmallLetter(c) || checkBigLetter(c)) return false;
	return true;
}

bool checkPassword(string pass)
{
	bool bigLetter = false, smallLetter = false, number = false, specialChar = false;
	for(int i = 0; i < pass.length(); i++)
	{
		char c = pass[i];
		bigLetter |= checkBigLetter(c);
		smallLetter |= checkSmallLetter(c);
		number |= checkNumber(c);
		specialChar |= checkSpecialChar(c);
	}

	return bigLetter && smallLetter && number && specialChar;
}
int main()
{
	int t;
	bool test;
	string password;
	cin >> t;
	getline(cin, password);	//	redundant new line
	while(t--)
	{
		test = false;
		getline(cin, password);

		if(password.length() >= 8 && checkPassword(password))
			cout << password << endl;
	}
}