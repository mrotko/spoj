#include <iostream>
#include <cmath>
using namespace std;


int perimeter(int &x)
{
	int a = sqrt(x);
	while(x % a) a--;
	int b = x/a;

	return 2*a + 2*b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t, area;
	cin >> t;

	while(t--)
	{
		cin >> area;
		cout << perimeter(area) << endl;
	}
}