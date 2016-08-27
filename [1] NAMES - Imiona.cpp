#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string uppercase(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] >= 'a' && name[i] <= 'z')
			name[i] -= ('a' - 'A');
	}
	return name;
}

bool compare(pair<string, int> &a, pair<string, int> &b)
{
	if(a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	map <string, int> count_name;
	vector<pair<string, int>> items;

	int nr;
	string rubbish, name;
	while (cin >> nr >> rubbish >> rubbish >> name)
		count_name[uppercase(name)]++;
	
	for (map<string, int>::iterator it = count_name.begin(); it != count_name.end(); ++it)
		items.push_back(make_pair(it->first, it->second));
	
	sort(items.begin(), items.end(), compare);
	for (int i = 0; i < items.size(); i++)
		cout << items[i].first << " " << items[i].second << endl;	
}