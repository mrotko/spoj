#include <iostream>
using namespace std;

int liczZdania(string tekst)
{
	int zdania = 0;
	for(unsigned i = 0; i < tekst.length(); i++)
	{
		if(tekst.at(i) == '?')
			zdania++;
		else if(tekst.at(i) == '!')
			zdania++;
		else if(tekst.at(i) == '.')
		{
			if(i + 2 < tekst.length() && tekst.at(i+2) == '.')
			{
				i += 2;
				zdania++;
			}
			else
				zdania++;
		}
	}
	return zdania;
}

int main()
{
	string linia;
	int zdania = 0;

	while(cin >> linia)
		zdania += liczZdania(linia);

	cout << zdania << endl;
}