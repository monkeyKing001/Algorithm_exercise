#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	a;
	cin >> a;
	for (int i=0; i<a; i++)
	{
		for (int j=0; j <= i; j++)	cout << '*';
		for (int j=0; j < 2 * (a - i - 1); j++)	cout << ' ';
		for (int j=0; j <= i; j++)	cout << '*';
		cout << '\n';
	}
	for (int i=0; i < a-1; i++)
	{
		for (int j=0; j < a-i-1; j++)	cout << '*';
		for (int j=0; j < 2 * (i+1); j++)	cout << ' ';
		for (int j=0; j < a-i-1; j++)	cout << '*';
		cout << '\n';
	}
	return (0);
}

