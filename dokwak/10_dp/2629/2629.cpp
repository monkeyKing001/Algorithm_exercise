#include <bits/stdc++.h>
#include <ctime>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<vector<bool>> possible;
vector<unordered_set<int>> possible_set;

char sol(vector<int> &w, int target){
	if (possible_set[n].find(target) == possible_set[n].end())
		return ('N');
	return ('Y');
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	std::vector<int> weights(n , 0);
	for (int i = 0; i < n; i++) cin >> weights[i];
	cin >> m;
	std::vector<int> marbles(m, 0);
	for (int i = 0; i < m; i++) cin >> marbles[i];
	possible.resize(n + 1, vector<bool>(40001, false));
	possible_set.resize(n + 1);
	possible_set[0].insert(0);
	for (int i = 0; i < n; i++) {
		int cur_w = weights[i];
		for (auto case_ : possible_set[i]){
			possible_set[i + 1].insert(case_);
			possible_set[i + 1].insert(case_ + cur_w);
			possible_set[i + 1].insert(abs(case_ - cur_w));
		}
	}
	for (int i = 0; i < m; i++) cout << sol(weights, marbles[i]) << '\n';
	return (0);
}

