#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	double w1, w2, w3;

	cin >> a1 >> b1 >> c1 >> d1;
	cin >> a2 >> b2 >> c2 >> d2;

	w1 = (b1 * b2 + d1 * d2) / (b2+d2);
	w2 = (a1 * a2 + c1 * c2) / (a2+c2);
	w3 = (a1*a2 + b1*b2 + c1*c2 + d1*d2) / (a2 + b2 + c2 + d2);
	cout << setprecision(2) <<  fixed << "K16K36: " << w1 << "\nM16M36: " << w2 << "\nM16K16M36K36: " << w3 << endl;
}