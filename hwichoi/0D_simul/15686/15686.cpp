#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int board[52][52];
pair<int, int> chkn[15];
pair<int ,int> house[102];
int dist[102][15];
int c, h, ret;
bool st[15];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) chkn[c++] = {i, j};
			else if (board[i][j] == 1) house[h++] = {i, j};
		}
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < c; ++j)
			dist[i][j] = abs(house[i].first - chkn[j].first) + abs(house[i].second - chkn[j].second);
	fill(st+m, st+c, 1);
	ret = 2147483647;
	do {
		int total = 0;
		for (int i = 0; i < h; ++i) {
			vector<int> tmp;
			for (int j = 0; j < c; ++j) {
				if (st[j]) continue;
				tmp.push_back(dist[i][j]);
			}
			total += *min_element(tmp.begin(), tmp.end());
		}
		if (ret > total) ret = total;
	} while (next_permutation(st, st+c));
	cout << ret << '\n';
	return (0);
}

