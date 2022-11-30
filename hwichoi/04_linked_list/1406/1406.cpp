#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string	init;
	cin >> init;
	list<char> L;
	for (auto c : init) L.push_back(c);
	int		i;
	cin >> i;
	auto cursor = L.end();
	while (i-- > 0)
	{
		char	op;
		cin >> op;
		if (op == 'L')
			if (cursor != L.begin()) cursor--;
		if (op == 'D')
			if (cursor != L.end()) cursor++;
		if (op == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		if (op == 'P') {
			char	c;
			cin >> c;
			L.insert(cursor, c);
		}
	}
	for (auto t : L) cout << t;
	cout << '\n';
	return (0);
}
