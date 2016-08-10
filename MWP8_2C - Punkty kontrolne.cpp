#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    vector <int> spot;

    cin >> t;
    while(t--)
    {
        cin >> n;
        spot.clear();

        if(n == 1)
        {
            cout << "0\n";
            continue;
        }

        for(int i = 1; i <= n/2; i++)
            if(n % i == 0) spot.push_back(i);

        cout << spot.size() * 2 - !(n % 2) << endl;

        for(int i = 0; i < spot.size(); i++)
        {
            cout << "1/" << n/spot[i] << " ";
            spot[i] = n / spot[i];
        }
        for(int i = spot.size()-1; i >= 0; i--)
            if(spot[i] != 2)
                cout << spot[i]-1 << "/" << spot[i] << " ";

        cout << endl;
    }
}
