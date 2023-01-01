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
	for (int e : b)
		a.push_back(e);
	int	buffer;
	for (int i = 0; i < a.size() - 1; i++)
	{
		int	j;
		j = i + 1;
		while (j < a.size())
		{
			if (a[i] > a[j])
			{
				buffer = a[i];
				a[i] = a[j];
				a[j] = buffer;
			}
			j++;
		}
	}
	for (int e : a)
		cout << e << ' ';
	cout << '\n';
	return (0);
}
