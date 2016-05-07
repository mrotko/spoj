#include <iostream>
#include <stack>
using namespace std;

long long operation(long long a, long long b, char c)
{
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	if(c == '/') return a / b;
}

int main()
{
	stack <long long> onp;

	long long type, l, q;
	char op;

	cin >> q;
	while(q--)
	{
		cin >> type;
		if(type)
		{
			cin >> l;
			onp.push(l);
		}
		else
		{
			cin >> op;
			long long x = onp.top();
			onp.pop();
			long long y = onp.top();
			onp.pop();
			onp.push(operation(y, x, op));
		}
	}

	cout << onp.top() << endl;
	cout << "ONP";
}