#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	string code;
	int ascii;
	cin >> code;

	for (unsigned int i = 0; i < code.length(); i += 2)
	{
		ascii = (code[i] - '0') * 10 + (code[i + 1] - '0');
		if (ascii < 30)
		{
			ascii = ascii * 10 + (code[i + 2] - '0');
			i++;
		}
		cout << char(ascii);
	}
}