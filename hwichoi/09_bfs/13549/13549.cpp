#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int n, m;
int dis[200002];
deque<int> Q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(dis, dis+200000, -1);
	cin >> n >> m;
	Q.push_back(n);
	dis[n] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop_front();
		int a, b, c;
		a = cur + 1;
		b = cur - 1;
		c = cur * 2;
		if (c >= 0 && c < 200000 && dis[c] == -1) {
			dis[c] = dis[cur];
			Q.push_front(c);
		}
		if (b >= 0 && b < 200000 && dis[b] == -1) {
			dis[b] = dis[cur] + 1;
			Q.push_back(b);
		}
		if (a >= 0 && a < 200000 && dis[a] == -1) {
			dis[a] = dis[cur] + 1;
			Q.push_back(a);
		}
	}
	cout << dis[m] << '\n';
	return (0);
}
