#include <bits/stdc++.h>
using namespace std;
int	n;
int	way = 0;
int	sol = 0;
bool **visited;
bool valid(int q_i, int position_i){
	//vertical check
	for (int r_i = 0; r_i < q_i; r_i++) {
		if (visited[r_i][position_i])
			return false;
	}
	//diagonal check
	for (int diagonal_len = 1; diagonal_len < n; diagonal_len++) {
		if (q_i - diagonal_len >= 0 &&
				position_i - diagonal_len >= 0 &&
				visited[q_i - diagonal_len][position_i - diagonal_len]){
			return false;
		}
		if (q_i - diagonal_len >= 0 &&
				position_i + diagonal_len < n &&
				visited[q_i - diagonal_len][position_i + diagonal_len]){
			return false;
		}
	}
	return (true);
}
void rec(int q_i){
	if (q_i == n){
		sol++;
		return;
	}
	//col check!!
	for (int position_i = 0; position_i < n; position_i++) {
		if (valid(q_i, position_i)){
			visited[q_i][position_i] = true;
			rec(q_i + 1);
			visited[q_i][position_i] = false;
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	visited = new bool*[n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			 visited[i][j] = false;
		}
	}
	rec(0);
	cout << sol;
	return (0);
}

