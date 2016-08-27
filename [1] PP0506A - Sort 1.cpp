#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int t, n, x[1000], y[1000], tmp;
    string nazwa[1000];
    double p_1, p_2;
    string tmp_nazwa;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>n;
        for(int j = 0; j<n; j++)
            cin>>nazwa[j]>>x[j]>>y[j];
        for(int j = 0; j<n; j++)
        {
            for(int k = 0; k<n - 1; k++)
            {
                p_1 = sqrt(x[k] * x[k] + y[k] * y[k]);
                p_2 = sqrt(x[k + 1] * x[k + 1] + y[k + 1] * y[k + 1]);
                if(p_1 > p_2)
                {
                    tmp = x[k];
                    x[k] = x[k + 1];
                    x[k + 1] = tmp;
                    tmp = y[k];
                    y[k] = y[k + 1];
                    y[k + 1] = tmp;
                    tmp_nazwa = nazwa[k];
                    nazwa[k] = nazwa[k + 1];
                    nazwa[k + 1] = tmp_nazwa;
                }
            }
        }
        for(int j = 0; j<n; j++)
            cout<<nazwa[j]<<" "<<x[j]<<" "<<y[j]<<endl;
    }
}