#include <bits/stdc++.h>

using namespace std;
int sol = 0;
int n, m;
int peopleNum;
int partyNum;
int truthNum;
set <int> truth;

int	main(int argc, char **argv)
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	peopleNum = n;
	partyNum = m;
	cin >> truthNum;
	vector<vector <int>> party(partyNum);
	for (int i = 0; i < truthNum; i++) {
		int know_truth;
		cin >> know_truth;
		truth.insert(know_truth);
	}
	return (0);
}

