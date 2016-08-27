#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, maxArea, t;
    char c;

    cin >> t;
    while(t--)
    {
        cin >> n;
        maxArea = -1;

        for(int i = 0, num; i < n; i++)
        {
            num = 0;
            for(int j = 0; j < n; j++)
            {
                cin >> c;
                if(c == '#')
                {
                    if(maxArea < num)
                        maxArea = num;
                    num = 0;
                }
                if(c == '.') num++;
            }
            if(maxArea < num)
                maxArea = num;
        }
        cout << maxArea*maxArea << endl;
    }
}
