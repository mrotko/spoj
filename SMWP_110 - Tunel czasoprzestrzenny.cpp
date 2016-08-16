#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int xg, yg, n, x, y, maxX, maxY;
	double maxOdleglosc = -1;
	double odlegloscTemp;

	cin >> xg >> yg >> n;
	while(n--) {
		cin >> x >> y;
		odlegloscTemp = sqrt(pow(xg - x, 2) + pow(yg - y, 2));
		if(odlegloscTemp > maxOdleglosc) {
			maxOdleglosc = odlegloscTemp;
			maxX = x; maxY = y;
		}
	}

	cout << maxX << " " << maxY << endl;
	cout << setprecision(2) << fixed << maxOdleglosc << endl;
}