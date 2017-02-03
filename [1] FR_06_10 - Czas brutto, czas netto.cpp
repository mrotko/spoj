#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Zawodnik
{
	string nazwisko;
	string imie;
	string czasBrutto;
	string czasNetto;
	string opoznienie;
	int czas;
};

void liczCzas(Zawodnik &x)
{
	int czas;
	int h,m,s;
	h = stoi(x.czasBrutto.substr(0, 2));
	m = stoi(x.czasBrutto.substr(3, 2));
	s = stoi(x.czasBrutto.substr(6, 2));

	czas = h * 3600 + m * 60 + s;

	m = stoi(x.opoznienie.substr(0, 2));
	s = stoi(x.opoznienie.substr(3, 2));

	czas -= (m*60 + s);
	x.czas = czas;

	h = czas / 3600;
	czas %= 3600;
	m = czas / 60;
	czas %= 60;
	s = czas;

	ostringstream sformatowanyCzas;

	if(h < 10)
		sformatowanyCzas << "0";
	sformatowanyCzas << h << ":";

	if(m < 10)
		sformatowanyCzas << "0";
	sformatowanyCzas << m << ":";

	if(s < 10)
		sformatowanyCzas << "0";
	sformatowanyCzas << s;

	x.czasNetto = sformatowanyCzas.str();
}

bool sortFunc(Zawodnik &a, Zawodnik &b)
{
	if(a.czas < b.czas)
		return true;
	if(b.czas < a.czas)
		return false;

	if(a.nazwisko < b.nazwisko)
		return true;
	if(b.nazwisko < a.nazwisko)
		return false;

	if(a.imie < b.imie)
		return true;
	if(b.imie < a.imie)
		return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	vector <Zawodnik> ranking;
	cin >> n;

	while(n--)
	{
		Zawodnik x;

		cin >> x.nazwisko >> x.imie >> x.czasBrutto >> x.opoznienie;
		liczCzas(x);

		ranking.push_back(x);
	}

	sort(ranking.begin(), ranking.end(), sortFunc);

	for(unsigned i = 0; i < ranking.size(); i++)
		cout 	<< i + 1 << " " << ranking.at(i).nazwisko << " " << ranking.at(i).imie << " " 
				<< ranking.at(i).czasNetto << " " << ranking.at(i).czasBrutto << endl;
}