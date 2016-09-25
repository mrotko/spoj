#include <iostream>
#include <vector>

using namespace std;

void podzb(vector <int> tabA, vector <int> tabB, int k) {
    if(k == 0) {
        for(int i = 0; i < tabB.size(); i++)
            cout << tabB[i] << " ";
        cout << endl;
    }
    else if(k == tabA.size()) {
        for(int i = 0; i < tabB.size(); i++)
            cout << tabB[i] << " ";
        for(int i = 0; i < tabA.size(); i++)
            cout << tabA[i] << " ";
        cout << endl;
    }
    else {

        tabB.push_back(tabA[0]);
        tabA.erase(tabA.begin());

        podzb(tabA, tabB, k - 1);
        tabB.pop_back();
        podzb(tabA, tabB, k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, k;
    vector <int> tabA, tabB;

    cin >> t;

    while(t--) {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            tabA.push_back(i + 1);

        podzb(tabA, tabB, k);
        tabA.clear();
    }
}