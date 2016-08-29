#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    map <long long, long long> stos;
    long long m, n, l;

    cin >> m >> n >> l;

    for(long long i = 0; i < m; ++i) {
        for(long long j = 0, x; j < n; ++j) {
            cin >> x;
            stos[x]++;
        }
    }

    long long sum = 0, x = 0, i = 0, maxWys;
    map <long long, long long>::iterator it;
    it = stos.begin();

    while(sum + x <= l && it != stos.end()) {
        sum += x;
        maxWys = it->first;
        i += it->second;
        it++;
        x = i * (it->first - maxWys);
    }
    maxWys += (l - sum) / i;

    long long fib1 = 1, fib2 = 1, c;

    while(fib1 <= maxWys) {
        c = fib1;
        fib1 = fib1 + fib2;
        fib2 = c;
    }

    cout << fib2 << endl;
}