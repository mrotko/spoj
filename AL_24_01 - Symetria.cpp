#include <iostream>
using namespace std;

unsigned long long reverseBits(unsigned long long num, int n)
{
	unsigned long long m = 0;
	for (int i = 0; i < n; i++, num >>= 1)
	{
		m <<= 1;
		m |= num & 1;
	}
	return m;
}


int main()
{
	ios_base::sync_with_stdio(0);
	int t;

	unsigned long long num = 0, order, numberOfBits, secondPart;
	cin >> t;
	while (t--)
	{
		num = 0;
		cin >> numberOfBits >> order;
		order--;
		
		num |= order;
		if (numberOfBits % 2 == 0) secondPart = reverseBits(num, numberOfBits / 2);
		else secondPart = reverseBits(num >> 1, numberOfBits / 2);
		num <<= numberOfBits / 2;
		num |= secondPart;
		cout << num << endl;
	}	
}