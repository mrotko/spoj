#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool testPalindrom(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    string s = a + b;
    for(int i = 0, j = s.length() - 1; i < j; i++, j--)
        if(s[i] != s[j])
            return false;
    return true;
}


int main() {
    vector <string> zbior1, zbior2;
    string s, palindrom = "";
    int n;

    cin >> n;
    while(n--) {
        cin >> s;
        zbior1.push_back(s);
    }

    cin >> n;
    while(n--) {
        cin >> s;
        zbior2.push_back(s);
    }

    for(int i = 0; i < zbior1.size(); i++) {
        for(int j = 0; j < zbior2.size(); j++) {
            if(zbior1[i].length() + zbior2[j].length() > palindrom.length()) {
                if(testPalindrom(zbior1[i], zbior2[j]))
                    palindrom = zbior1[i] + zbior2[j];
                else if(testPalindrom(zbior2[j], zbior1[i]))
                    palindrom = zbior2[j] + zbior1[i];
            }
        }
    }
    if(palindrom == "") cout << "0" << endl;
    else cout << palindrom.length() << endl << palindrom << endl;
}