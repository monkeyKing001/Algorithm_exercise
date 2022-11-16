#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, x;
	int	input;

	cin >> n >> x;
	for (int i=0; i<n; i++)
	{
		cin >> input;
		if (input < x)
			cout << input << ' ';
	}
	return (0);
}
