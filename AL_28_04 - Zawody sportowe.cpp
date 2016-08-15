#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector <int> &tab, int value)
{
	int position, left = 0, right = tab.size()-1;
	while(left <= right) {
		position = (left + right) / 2;

		if(position > 0 && tab[position] >= value && tab[position - 1] < value)
			break;

		if(tab[position] >= value)
			right = position - 1;
		if(tab[position] < value)
			left = position + 1;
	}

	return position;
}


int main() {
	ios_base::sync_with_stdio(0);
	int minPoints, maxPoints, a, b;
	vector <int> rankingList;
	int numberOfCompetitions, numberOfPlayers, data;

	cin >> data;

	while(data--) {
		cin >> numberOfCompetitions >> numberOfPlayers;

		minPoints = 0; maxPoints = 0;
		for(int i = 0; i < numberOfCompetitions; i++) {
			cin >> a >> b;
			minPoints += a; maxPoints += b;
		}

		for(int i = 0; i < numberOfPlayers; i++) {
			cin >> a;
			rankingList.push_back(a);
		}

		sort(rankingList.begin(), rankingList.end());

		int count = 1, index = binarySearch(rankingList, minPoints), last_value = minPoints;

		while(index < rankingList.size() && rankingList[index] <= maxPoints) {
			if(rankingList[index] >= minPoints && last_value != rankingList[index])
				count++;
			last_value = rankingList[index];
			index++;
		}

		cout <<  count << endl;
		rankingList.clear();
	}
}
