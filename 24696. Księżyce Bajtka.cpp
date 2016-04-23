#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	double r1, r2;
	int t;
	cin >> t;

	while (t--)
	{
		cin >> r1 >> r2;
		cout << fixed << setprecision(2) << 2 * r1* r2 << endl;
	}
}