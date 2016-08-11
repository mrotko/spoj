#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t, n, a, count;
	long long s, l;

	vector <int> ciag;

	cin >> t;
	while (t--)
	{
		cin >> n;
		s = 0; count = 0; l = 0;
		while (n--)
		{
			cin >> a;
			s += a;
			ciag.push_back(a);
		}
		for (int i = 0; i < ciag.size()-1; i++)
		{
			l += ciag[i];
			s -= ciag[i];
			if (l == s) count++;
		}
		cout << count << endl;
		ciag.clear();
	}
}