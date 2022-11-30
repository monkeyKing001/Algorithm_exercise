#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<int> L = {1, 2};
	list<int>::iterator t = L.begin();
	L.push_front(10);
	cout << *t << '\n';
	L.push_back(5);
	L.insert(t, 6);
	t++;
	t = L.erase(t);
	cout << *t << '\n';
	for (auto i : L) cout << i << ' ';
	cout << '\n';
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
		cout << *it << ' ';
	return (0);
}

