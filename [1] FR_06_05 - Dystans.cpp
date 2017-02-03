#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Punkt
{
	int x,y;
};

double odleglosc(Punkt &a, Punkt &b)
{
	return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main()
{
	ios_base::sync_with_stdio(0);
	double droga;
	Punkt a, b;

	int d, n;
	cin >> d;

	while(d--)
	{
		cin >> n;
		droga = 0;
		cin >> a.x >> a.y;
		n--;
		while(n--)
		{
			cin >> b.x >> b.y;
			droga += odleglosc(a, b);
			a = b;
		}
		cout << setprecision(2) << fixed << droga / 1000 << endl;
	}
}