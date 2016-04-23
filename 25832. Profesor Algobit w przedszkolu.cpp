#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	string code;
	getline(cin, code);
	for (int i = 0; i < code.length(); i += 2)
		cout << code[i];

	int back;
	if (code.length() % 2) back = 2;
	else back = 1;
	for (int i = code.length() - back ; i > 0; i -= 2)
		cout << code[i];
}