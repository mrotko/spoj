#include <iostream>
#include <map>
#include <vector>
using namespace std;


struct Produkt {
    long long ilosc;
    int index;
};


int main() {
    ios_base::sync_with_stdio(0);
    map <int, int> index;
    vector <Produkt> zestawienie;

    int n, a, b;

    cin >> n;

    while(n--) {
        cin >> a >> b;

        if(index[a] == 0) {
            zestawienie.push_back(Produkt {b, a});
            int i = zestawienie.size();
            index[a] = i;
        }
        else {
            int i = index[a] - 1;
            zestawienie[i].ilosc += b;
        }
    }

    cout << zestawienie.size() << endl;

    for(int i = 0; i < zestawienie.size(); i++)
        cout << zestawienie[i].index << " " << zestawienie[i].ilosc << endl;
}