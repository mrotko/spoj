#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	long long circumference, area, tests;

	cin >> tests;
	while (tests--)
	{
		cin >> circumference;
		if (circumference % 2)
			cout << "BRAK\n";
		else
		{
			long long b = circumference / 4;
			long long a = circumference/2 - b;

			area = a*b;
			if (area) 
				cout << area << endl;
			else cout << "BRAK\n";
		}
	}
}