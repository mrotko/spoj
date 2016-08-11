// trzeba policzyæ jedynki w n nieparzystym, je¿eli iloœæ jedynek % 2 jest nieparzysta to wygrywa 1, je¿eli parzysta to wygrywa 2
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	long long n;
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		if (n % 2 == 0)
			cout << n / 2 << " " << n / 2 << endl;
		else
		{
			int count = 0;
			long long tmp, half = n / 2;
			while (n)
			{
				tmp = n;
				tmp = tmp >> 1 << 1;
				if (n - tmp)
					count++;
				n = n >> 1;				
			}
			if (count % 2) cout << half + 1 << " " << half << endl;
			else cout << half << " " << half + 1 << endl;
		}
	}
}