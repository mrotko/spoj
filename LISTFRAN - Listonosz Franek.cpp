#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int a, b, n, poczta, euler;

	cin >> n >> poczta;
	euler = poczta;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		euler ^= a;
		euler ^= b;
	}

	if(euler == poczta) cout << "TAK\n";
	else cout << "NIE\n";

}