#include <iostream>
#include <cmath>
using namespace std;

const int large = 10000001;

bool prime[large];

int main()
{
	ios_base::sync_with_stdio(0);
	long long factorial, primeNumber, result, tests, maxPrime;

	prime[0] = prime[1] = true;

	for (int i = 2; i <= sqrt(large); i++)
	{
		if (prime[i]) continue;
		for (int j = 2 * i; j < large; j += i)
			prime[j] = true;
	}

	cin >> tests;

	while (tests--)
	{
		result = 0;
		cin >> factorial >> maxPrime;
		while (prime[maxPrime--]);
		primeNumber = maxPrime + 1;
		long long primeNumberPower = primeNumber;
		while (factorial / primeNumberPower)
		{
			result += factorial / primeNumberPower;
			primeNumberPower *= primeNumber;
		}
		cout << result << endl;
	}
}
