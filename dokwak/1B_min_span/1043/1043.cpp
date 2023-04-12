#include <bits/stdc++.h>

using namespace std;
int parent[51];
int total_people_num;
int party_num;
int truth_num;
int party_member_num;

int find_parent(int v1)
{
	if (parent[v1] == 0)
		return (v1);
//	cout << "fnding "
//		<< v1
//		<< "'s parent : "
//		<< parent[v1]
//		<< "\n";
	parent[v1] = find_parent(parent[v1]);
//	cout << "now " << v1 << "'s parent is " << parent[v1] << "\n";
	return (parent[v1]);
}

void union_parent(int v1, int v2)
{
//	cout << "joinging "
//		<< v1
//		<< ", "
//		<< v2
//		<< "\n";
	v1 = find_parent(v1);
	v2 = find_parent(v2);
	if (v1 == v2)
		return ;
	if (v1 > v2)
		swap(v1, v2);
	parent[v2] = v1;
//	cout << "now " << v2 << "'s parent is " << v1 << "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> total_people_num >> party_num;
	vector <vector<int> > party(party_num + 1);
	cin >> truth_num;
	vector <int> truth_people(truth_num + 1);

	//input who know the truth
	for (int i = 0; i < truth_num; i++)
	{
		int temp;
		cin >> temp;
		truth_people[i] = temp;
	}
	//short cut case
	if (truth_num == 0)
	{
		cout << party_num;
		return (0);
	}
	//party member input
	for (int i = 0; i < party_num; i++)
	{
		cin >> party_member_num;
		for (int j = 0; j < party_member_num; j++)
		{
			int temp_people;
			int party_host;
			cin >> temp_people;
			party[i].push_back(temp_people);
			if (j == 0)
				party_host = temp_people;
			else
			{
				union_parent(party_host, temp_people);
			};
		}
	}
	int sol = 0;
	for (int i = 0; i < party_num; i++)
	{
		int flag = 0;
		for (int j = 0; j < party[i].size(); j++)
		{
			int m = party[i][j];
			for (int k = 0; k < truth_num; k++)
			{
				if (find_parent(m) == find_parent(truth_people[k]))
				{
					flag = 1;
					break;
				}
			}
			if (j == party[i].size() - 1 && flag == 0)
				sol++;
		}
	}
	cout << sol;
	return (0);
}

