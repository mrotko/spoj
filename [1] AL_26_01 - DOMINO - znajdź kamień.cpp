#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	const int size = 7;
	int domino[size][size];
	int tests;
	cin >> tests;

	while (tests--)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				domino[i][j] = 0;
		int a, b;
		char c;
		for (int i = 0; i < 27; i++)
		{
			cin >> a >> c >> b;
			domino[a][b] = 1;
			domino[b][a] = 1;
		}

		for (int i = 0, end = 0; i < 8; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (domino[i][j] == 0)
				{
					cout << i << "|" << j << endl;
					end = 1;
					break;
				}
			}
			if (end) break;
		}
	}
}