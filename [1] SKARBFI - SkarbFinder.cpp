#include <iostream>
using namespace std;
int main()
{
	int polnoc, poludnie, zachod, wschod;
	int polnoc_poludnie, zachod_wschod;
	int x, y;
	int a, b;
	int kierunek_1, kierunek_2;
	int kroki_1, kroki_2;
	cin >> x;

	for (int i = 0; i < x; i++)
	{
		polnoc = 0;
		poludnie = 0;
		zachod = 0;
		wschod = 0;
		cin >> y;
		for (int j = 0; j < y; j++)
		{
			cin >> a >> b;
			if (a == 0) polnoc += b;
			if (a == 1) poludnie += b;
			if (a == 2) zachod += b;
			if (a == 3) wschod += b;
		}
		polnoc_poludnie = polnoc - poludnie;
		zachod_wschod = zachod - wschod;
		if (polnoc_poludnie == 0 && zachod_wschod == 0)
		{
			cout << "studnia" << endl;
			continue;
		}
		if (polnoc_poludnie > 0)
		{
			kierunek_1 = 0;
			kroki_1 = polnoc_poludnie;
		}
		else
		{
			kierunek_1 = 1;
			kroki_1 = -polnoc_poludnie;
		}
		if (zachod_wschod > 0)
		{
			kierunek_2 = 2;
			kroki_2 = zachod_wschod;
		}
		else
		{
			kierunek_2 = 3;
			kroki_2 = -zachod_wschod;
		}
		if(kroki_1 == 0) cout<<kierunek_2<<" "<<kroki_2<<endl;
		else if(kroki_2 == 0) cout<<kierunek_1<<" "<<kroki_1<<endl;
		else cout<<kierunek_1<<" "<<kroki_1<<"\n"<<kierunek_2<<" "<<kroki_2<<endl;
	}
}
