#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t, k, n;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (n % 2) cout << "BRAK\n";
		else
		{
			if (k > n / 2) cout << k - n / 2 << endl;
			else cout << k + n / 2 << endl;
		}
	}
}