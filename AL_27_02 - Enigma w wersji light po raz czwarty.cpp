#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string word;
    char character;
    while(cin >> word)
    {
        cin.get(character);
        cout << word[0];
        if(word.find(".") != string::npos && character != '\n') cout << " ";
        if(character == '\n')
            cout << endl;
    }
}
