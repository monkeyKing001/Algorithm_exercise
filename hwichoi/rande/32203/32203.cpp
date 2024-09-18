#include <iostream>

using namespace std;
using ll = long long;
int n, m;
int p[101010];
pair<ll, ll> t[101010];

int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	t[x] = {t[x].first + t[y].first, t[x].second + t[y].second};
	p[y] = x;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) p[i] = i;
	for (int i = 1; i <= n; ++i) {
		int input;
		cin >> input;
		if (input % 2 == 1) t[i] = {1, 0};
		else t[i] = {0, 1};
	}
	long long total = 0;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << total << '\n';
			continue;
		}
		pair<ll, ll> p1 = t[p[a]];
		pair<ll, ll> p2 = t[p[b]];
		total -= p1.first*p1.second + p2.first*p2.second;
		uni(a, b);
		pair<ll, ll> p3 = t[p[a]];
		total += p3.first*p3.second;
		cout << total << '\n';
	}
}

