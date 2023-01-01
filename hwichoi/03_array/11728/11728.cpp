#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	an, bn;
	cin >> an >> bn;
	vector<int>	a;
	vector<int> b;
	int	input;
	while (an--)
	{
		cin >> input;
		a.push_back(input);
	}
	while (bn--)
	{
		cin >> input;
		b.push_back(input);
	}
	vector<int> c;
	an++;
	bn++;
	while (an < a.size() || bn < b.size())
	{
		if ((a[an] > b[bn] || an >= a.size()) && bn < b.size())
			c.push_back(b[bn++]);
		else
			c.push_back(a[an++]);
	}
	for (int e : c)
		cout << e << ' ';
	cout << '\n';
	return (0);
}
