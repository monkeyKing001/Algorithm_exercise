#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int tc, n;
int board[100005];
int state[100005];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> board[i];
		}
		int res = 0;
		fill(state+1, state + n+1, 0);
		for (int i = 1; i <= n; ++i) {
			if(state[i] != 0) continue;
			int cur = i;
			while (1) {
				state[cur] = i;
				cur = board[cur];
				// if in cycle of this case
				if (state[cur] == i) {
					while (state[cur] != -1) {
						state[cur] = -1;
						cur = board[cur];
					}
					break;
				}
				// if not visited
				else if (state[cur] != 0) break;
			}
		}
		for (int i = 1; i <= n; ++i)
			if (state[i] != -1) ++res;
		cout << res << '\n';
	}
	return (0);
}

