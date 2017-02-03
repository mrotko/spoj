#include <iostream>
#include <GL/glut.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string anagram;
    int ile = 0, n;
    int tab[30], tab2[30];

    for(int i = 0; i < 30; i++)
        tab[i] = 0;

    cin >> anagram >> n;

    for(int i = 0; i < anagram.length(); i++)
        tab[anagram.at(i) - 'a']++;

    while(n--) {
        for(int i = 0; i < 30; i++)
            tab2[i] = 0;
        cin >> anagram;

        for(int i = 0; i < anagram.length(); i++)
            tab2[anagram.at(i) - 'a']++;

        bool test = true;
        for(int i = 0; i < 30; i++)
        {
            if(tab[i] != tab2[i])
            {
                test = false;
                break;
            }
        }

        if(test) ile++;
    }

    cout << ile << endl;
}