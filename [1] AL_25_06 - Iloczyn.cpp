#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = 4611686018427387847;

ll pow_by_10(ll l, int n) {
    ll result = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < 10; i++)
            result = (result + l) % mod;
        l = result;
        result = 0;
    }
    return l;
}

int len(ll a) {
    int l = 1;
    while(a /= 10)
        l++;
    return l;
}

ll karacuba(ll num1, ll num2) {
    int l1, l2;
    l1 = len(num1);
    l2 = len(num2);

    if(l1 + l2 <= 17)
        return (num1 * num2) % mod;

    if(l1 == 1 || l2 == 1) {
        if(l1 == 1)
            swap(num1, num2);
        ll result = 0;
        for(int i = 0; i < num2; i++)
            result = (result + num1) % mod;
        return result;
    }

    ll m = max(l1, l2);
    ll m2 = m / 2;

    ll begin1, end1, begin2, end2, p = pow(10, m2);
    begin1 = num1 / p;
    end1 = num1 % p;
    begin2 = num2 / p;
    end2 = num2 % p;
    ll X = karacuba(begin1, begin2);
    ll Y = karacuba(end1, end2);
    ll Z = karacuba(begin1 + end1, begin2 + end2) - X - Y;
    if(Z < 0) Z += mod;

    ll a = pow_by_10(X, 2 * m2);
    ll b = pow_by_10(Z, m2);


    return ((a + b) % mod + Y) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    ll a, b, result;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll x = b - a;
        a %= mod;
        result = a;
        a++;
        for(ll i = 0; i < x; i++) {
            result = karacuba(result, a);
            a++;
        }
        cout << result << endl;
    }
}
