#include <iostream>
using namespace std;

bool symulacja(int plansza[5][5]) {
    int plansza_tmp[5][5];
    int time = 100;

    while(time--) {
        int y = 4;
        for(int i = 0; i < 5; i++, y++) {
            y %= 5;
            int x = 4;
            for(int j = 0; j < 5; j++, x++) {
                x %= 5;
                int otoczenie = 0;

                for(int a = 0; a < 3; a++) {
                    for(int b = 0; b < 3; b++) {
                        int xx = (x + b) % 5;
                        int yy = (y + a) % 5;

                        if(xx == j && yy == i)
                            continue;
                        otoczenie += plansza[yy][xx];
                    }
                }
                if(otoczenie == 2)
                    plansza_tmp[i][j] = plansza[i][j];
                else if(otoczenie == 3)
                    plansza_tmp[i][j] = 1;
                else if(otoczenie < 2 || otoczenie > 3)
                    plansza_tmp[i][j] = 0;
            }
        }

        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                plansza[i][j] = plansza_tmp[i][j];
    }

    int count = 0;

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            count += plansza[i][j];

    return (count > 0);
}

int main() {
    int plansza[5][5];
    int t, w;

    cin >> t;

    while (t--) {
        for(int i = 0; i < 5; i++) {
            int c = cin.get();
            for (int j = 0; j < 5; j++)
                plansza[i][j] = cin.get() - '0';
        }

        if(symulacja(plansza)) cout << "yes\n";
        else cout << "no\n";

    }
}