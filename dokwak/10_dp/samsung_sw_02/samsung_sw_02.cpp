#include <iostream>
#include <vector>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input, n, m, q;
	cin >> input;
	for (int cnt = 1; cnt <= input; ++cnt) {
		cin >> n >> m >> q;
		int** arr = new int*[n];
		for (int i = 0; i < n; ++i) {
			arr[i] = new int[m];
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j];
			}
		}

		int ret = 0;
		vector<pair<int, int>> safe;
		for (int i = 0; i < n; ++i) {
			int high = 0;
			int flag = 0;
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] > arr[i][high]) high = j;
			}
			for (int k = 0; k < n; ++k) {
				if (arr[k][high] > arr[i][high]) {
					flag = 1;
					break;
				}
			}
			if (!flag) safe.push_back({i, high});
		}
		int x, y, z;
		for (int i = 0; i < q; ++i) {
			cin >> x >> y >> z;
			--x; --y;
			arr[x][y] = z;
			int mod = 0;
			for (int i = 0; i < safe.size(); ++i) {
				pair<int, int> tmp = safe[i];
				if (tmp.first == x || tmp.second == y) {
					++mod;
					if (arr[tmp.first][tmp.second] < z) {
						safe.erase(safe.begin()+i);
						--i;
						--mod;
					}
				}
			}
			if (!mod) safe.push_back({x, y});
			ret += safe.size();
		}
		cout << "#" << cnt << " " << ret << endl;
	}
	return (0);
}
