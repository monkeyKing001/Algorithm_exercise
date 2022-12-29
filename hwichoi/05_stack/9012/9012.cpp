#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;
	while (n--)
	{
		int	cnt = 0;
		string	s;
		for (char c : s)
		{
			if (c == '(')
				cnt++;
			else if (c == ')')
				cnt--;
		}
		if (cnt == 0)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return (0);
}

