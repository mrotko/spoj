#include <iostream>
using namespace std;

int ab(int a)
{
    if(a > 0) return a;
    else return -a;
}
int main()
{
    char wiatraczek[401][401];
    int n, k, j;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < 2*ab(n); i++)
            for(int j = 0; j < 2*ab(n); j++) wiatraczek[i][j] = '.';
        if(n > 0)
        {

            for(int i = 0; i < 2*n; i++)
            {
                if(i < n)
                {
                    k = i+1;
                    j = 0;
                }
                else
                {
                    k = 2*n - i;
                    j = -(2*n-1);
                }
                while(k)
                {
                    wiatraczek[i][ab(j)] = '*';
                    k--;
                    j++;
                }
            }
            for(int i = 0; i < 2*n; i++)
            {
                if(i < n)
                {
                    k = n-i;
                    j = n;
                }
                else
                {
                    k = i-n+1;
                    j = -n + 1;
                }
                while(k)
                {
                    wiatraczek[i][ab(j)] = '*';
                    k--;
                    j++;
                }
            }
        }
        else
        {
            n = ab(n);
            for(int i = 0; i < 2*n; i++)
            {
                if(i < n)
                {
                    k = n-i;
                    j = n-1;
                }
                else
                {
                    k = i-n+1;
                    j = -n;
                }
                while(k)
                {
                    wiatraczek[i][ab(j)] = '*';
                    k--;
                    j--;
                }
            }
            for(int i = 0; i < 2*n; i++)
            {
                if(i < n)
                {
                    k = i+1;
                    j = 2*n-1;
                }
                else
                {
                    k = 2*n-i;
                    j = 0;
                }
                while(k)
                {
                    wiatraczek[i][ab(j)] = '*';
                    k--;
                    j--;
                }
            }
        }
        for(int i = 0; i < 2*n; i++)
        {
            for(int j = 0; j < 2*n; j++) cout << wiatraczek[i][j];
            cout << endl;
        }
    }
}