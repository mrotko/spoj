#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Typ
{
	string gospodarz;
	string gosc;
	int gole_gospodarz = 0, gole_gosc = 0;
	int typowany_wynik[3] = {0,0,0};
	int prawdziwy_wynik[3] = {0,0,0};
	bool poprawnosc_typu;
	
	bool dodaj_gola(string &nazwa);
	void ocen_wynik();
	
	bool sprawdz_poprawnosc();
};

bool Typ::dodaj_gola(string &nazwa)
{
	if(gospodarz == nazwa)
	{
		gole_gospodarz++;
		return true;
	}
	if(gosc == nazwa)
	{
		gole_gosc++;
		return true;
	}
	return false;
}

void Typ::ocen_wynik()
{
	if(gole_gospodarz > gole_gosc)
		prawdziwy_wynik[1] = 1;
	else if(gole_gospodarz == gole_gosc)
		prawdziwy_wynik[0] = 1;
	else
		prawdziwy_wynik[2] = 1;
	
	poprawnosc_typu = sprawdz_poprawnosc();
}

bool Typ::sprawdz_poprawnosc()
{
	for(unsigned i = 0; i < 3; i++)
		if(typowany_wynik[i] == 1 && prawdziwy_wynik[i] == 1)
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int ilosc_kuponow, ilosc_meczow, ilosc_bramek;
	string gospodarz, gosc, pauza, typowany_wynik, nazwa_druzyny;
	
	vector <Typ> kupon;
	
	
	cin >> ilosc_kuponow;	
	while(ilosc_kuponow--)
	{
		
		cin >> ilosc_meczow;
		while(ilosc_meczow--)
		{
			cin >> gospodarz >> pauza >> gosc >> typowany_wynik;
			
			Typ typ;
			typ.gospodarz = gospodarz;
			typ.gosc = gosc;
			
			if(typowany_wynik.length() == 1)
			{
				int i = typowany_wynik.at(0) - '0';
				typ.typowany_wynik[i] = 1;
			}
			else
			{
				
				int i = typowany_wynik.at(0) - '0', j = typowany_wynik.at(1) - '0';
				typ.typowany_wynik[i] = typ.typowany_wynik[j] = 1;
			}
			
			kupon.push_back(typ);
		}
		
		cin>> ilosc_bramek;
		while(ilosc_bramek--)
		{
			cin >> nazwa_druzyny;
			
			for(unsigned i = 0; i < kupon.size(); i++)
				if(kupon.at(i).dodaj_gola(nazwa_druzyny) == true)
					break;
		}
		
		int dobre = 0;
		for(unsigned i = 0; i < kupon.size(); i++)
		{
			kupon.at(i).ocen_wynik();
			if(kupon.at(i).poprawnosc_typu == true)
				dobre++;
		}
		
		if(dobre == kupon.size())
			cout << "TAK" << endl;
		else
			cout << "NIE " << dobre << "/" << kupon.size() << endl;
		
		kupon.clear();
	}
}