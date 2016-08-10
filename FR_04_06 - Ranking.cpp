#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Player
{
public:
	string name;
	int id, rank, victory;
	double points;

	Player(string _name, int _id, int _rank)
	{
		name = _name;
		id = _id;
		rank = _rank;
		victory = 0;
		points = 0;
	}
};

class Tournament
{
private:
	vector <Player> list_of_players;

public:
	Tournament(int number_of_players)
	{
		for (int i = 0; i <= number_of_players; i++)
			list_of_players.push_back(Player("", 0, 0));
	}

	void add_player(Player player)
	{
		list_of_players[player.id] = player;
	}

	void show_table()
	{
		sort_table(1, list_of_players.size()-1);
		for (int i = 1; i < list_of_players.size(); i++)
			cout << i << " " << list_of_players[i].name << " " << fixed << setprecision(1) << list_of_players[i].points << endl;
	}

	void duel(int id_1, int id_2, char result)
	{
		if (result == 'W')
		{
			list_of_players[id_1].points += 1;
			list_of_players[id_1].victory += 1;				
		}
		else if (result == 'P')
		{
			list_of_players[id_2].points += 1;
			list_of_players[id_2].victory += 1;
		}
		else
		{
			list_of_players[id_1].points += 0.5;
			list_of_players[id_2].points += 0.5;
		}
	}

	int compare(Player first, Player second)
	{
		if (first.points > second.points)
			return 1;
		else if (first.points < second.points)
			return 2;
		if (first.victory > second.victory)
			return 1;
		else if (first.victory < second.victory)
			return 2;
		if (first.rank > second.rank)
			return 1;
		else if (first.rank < second.rank)
			return 2;
		if (first.name < second.name)
			return 1;
		else if (first.name > second.name)
			return 2;
		return 3;
	}

	void sort_table(int left, int right)
	{
		Player v = list_of_players[(left + right) / 2];
		int i, j;
		i = left;
		j = right;
		do
		{
			while (compare(list_of_players[i], v) == 1) i++;
			while (compare(list_of_players[j], v) == 2) j--;
			if (i <= j)
			{
				swap(list_of_players[i], list_of_players[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (j>left) sort_table(left, j);
		if (i<right) sort_table(i, right);
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	int test, number_of_players, number_of_rounds;

	cin >> test;
	
	while (test--)
	{
		cin >> number_of_players >> number_of_rounds;
		number_of_rounds = ((number_of_players + 1) >> 1) * number_of_rounds;
		
		Tournament game(number_of_players);
		int id, rank;
		string name;
		while (number_of_players--)
		{
			cin >> id >> name >> rank;
			game.add_player(Player(name, id, rank));
		}

		int id_1, id_2;
		char result;
		while (number_of_rounds--)
		{
			cin >> id_1 >> id_2 >> result;
			game.duel(id_1, id_2, result);			
		}
		game.show_table();
	}
}