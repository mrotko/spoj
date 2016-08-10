#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int size;
	int matrixA[10][10], matrixB[10][10];
	long long sum;
	while (cin >> size)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> matrixA[i][j];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> matrixB[i][j];

		for (int i = 0; i < size; i++)
		{			
			for (int j = 0; j < size; j++)
			{
				sum = 0;
				for (int k = 0; k < size; k++)
					sum += matrixA[i][k] * matrixB[k][j];
				cout << sum << " ";
			}			
		}
		cout << endl;
	}
}