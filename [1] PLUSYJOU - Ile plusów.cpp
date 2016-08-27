#include <iostream>
#include <vector>
using namespace std;

struct Coordinates
{
	int x, y;
};

int main()
{
	ios_base::sync_with_stdio(0);
	vector <Coordinates> plus;
	int size, sum = 0;
	cin >> size;
	bool **matrix = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		char c = cin.get();
		matrix[i] = new bool[size];
		for (int j = 0; j < size; j++)
		{
			c = cin.get();			
			matrix[i][j] = c - '0';
			if (matrix[i][j])
				if (i - 2 >= 0 && j - 1 >= 0 && j + 1 < size)
					if (matrix[i - 1][j] && matrix[i - 2][j] && matrix[i - 1][j - 1] && matrix[i - 1][j + 1])
						plus.push_back({ i - 1, j });
		}		
	}
	for (int i = 0; i < plus.size(); i++)
	{
		int next = 1, x = plus[i].x, y = plus[i].y;
		
		if (matrix[x - next][y - next] || matrix[x - next][y + next] || matrix[x + next][y + next] || matrix[x + next][y - next]) 
			continue;
		sum++; next++;
		while (x - next >= 0 && x + next < size && y - next >= 0 && y + next < size)
		{
			bool test = 0;
			if (matrix[x - next][y - next] || matrix[x - next][y + next] || matrix[x + next][y + next] || matrix[x + next][y - next]) 
				break;
			if (matrix[x][y + next] && matrix[x][y - next] && matrix[x + next][y] && matrix[x - next][y])
			{
				for (int j = 1; j < next; j++)
				{
					if (matrix[x - next + j][y - next] || matrix[x - next + j][y + next] || matrix[x + next - j][y + next] || matrix[x + next - j][y - next])
						test = true;
					if (matrix[x - next][y - next + j] || matrix[x - next][y + next - j] || matrix[x + next][y + next - j] || matrix[x + next][y - next + j])
						test = true;
					if (test) break;
				}
				if (test) break;
				sum++; next++;
			}
		}
	}
	cout << sum;
}