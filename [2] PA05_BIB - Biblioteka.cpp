#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map <int, vector <int>> plik;
    vector <int> kolejnosc;

    int t, n, s;
    long long czas;

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> s;
            plik[s].push_back(i);
        }
        map <int, vector <int>>::iterator it;

        while(plik.size() > 1 || (plik.size() == 1 && plik.begin()->second.size() > 1)) {
            int a, b;
            it = plik.begin();
            if(it->second.size() > 1) {
                a = it->second.back();
                it->second.pop_back();
                b = it->second.back();
                it->second.pop_back();
                s = it->first * 2;
                if(it->second.size() == 0)
                    plik.erase(it);
            }
            else {
                a = it->second.back();
                b = next(it)->second.back();
                s = it->first + next(it)->first;
                if(next(it)->second.size() > 1) {
                    next(it)->second.pop_back();
                    plik.erase(it);
                }
                else {
                    plik.erase(plik.begin());
                    plik.erase(plik.begin());
                }
            }

            czas += s;
            plik[s].push_back(min(a, b));
            kolejnosc.push_back(min(a, b) + 1);
            kolejnosc.push_back(max(a, b) + 1);
        }

        cout << czas << endl;
        for(int i = 0; i < kolejnosc.size() - 1; i += 2)
            cout << kolejnosc[i] << " " << kolejnosc[i + 1] << endl;

        kolejnosc.clear();
        plik.clear();
        czas = 0;
    }
}