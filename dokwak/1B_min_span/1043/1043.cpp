#include <bits/stdc++.h>

using namespace std;
int sol = 0;
int n, m;
int peopleCount;
int partyCount;
int truthCount;
vector <int> truth;
vector<int> parent(55, -1);

int find_p(int u){
	if (parent[u] == -1)
		return u;
	return find_p(parent[u]);
}

void union_u_v(int u, int v){
	int p_u = find_p(u);
	int p_v = find_p(v);
	if (p_u == p_v)
		return;
	if (p_v < p_u) {
		int temp = p_u;
		p_u = p_v;
		p_v = temp;
	}
	parent[p_v] = p_u;
}

int	main(int argc, char **argv)
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	peopleCount = n;
	partyCount = m;
	cin >> truthCount;
	vector<vector <int>> party(partyCount);

	//truth info input
	for (int i = 0; i < truthCount; i++) {
		int know_truth;
		cin >> know_truth;
		truth.push_back(know_truth);
	}

	//party info input
	for (int i = 0; i < partyCount; i++) {
		int partyPeopleCount;
		cin >> partyPeopleCount;
		for (int j = 0; j < partyPeopleCount; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
		}
		sort(party[i].begin(), party[i].end());
		for (int j = 0; j < party[i].size() - 1; j++) {
			int u = party[i][j];
			int v = party[i][j + 1];
			union_u_v(u, v);
		}
	}

	int countLieParty = 0;
	for (int i = 0; i < partyCount; i++) {
		bool safeToLieParty = true;
		for (int j = 0; j < party[i].size() && safeToLieParty; j++) {
			int num = party[i][j];
			for (int k = 0; k < truth.size() && safeToLieParty; k++) {
				int know_truth = truth[k];
				//if someone is same party with another who know the truth, cannot lie
				if (find_p(num) == find_p(know_truth))
					safeToLieParty = false;
			}
		}
		if (safeToLieParty)
			countLieParty++;
	}
	cout << countLieParty;
	return (0);
}

