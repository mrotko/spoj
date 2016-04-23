#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int tests, s, n, a;

	cin >> tests;
	while (tests--)
	{
		cin >> n;
		s = 0;
		while (n--)
		{
			cin >> a;
			s ^= a;
		}
		cout << s << endl;
	}
}