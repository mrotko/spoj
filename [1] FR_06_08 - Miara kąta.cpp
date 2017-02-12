#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double STOPNIE_GODZINA = 360 / 12;
    double STOPNIE_MINUTA = 360 / 60;

    int t;
    double godzina, minuta, stopnie;
    char c;

    cin >> t;
    while(t--)
    {
        cin >> godzina >> c >> minuta;

        stopnie = STOPNIE_GODZINA * godzina + STOPNIE_GODZINA * (minuta / 60) - STOPNIE_MINUTA * minuta;

        while(stopnie >= 360)
            stopnie -= 360;

        while(stopnie < 0)
            stopnie += 360;

        if(stopnie > 180)
            stopnie = 360 - stopnie;

        cout << setprecision(1) << fixed << stopnie << endl;
    }
}
