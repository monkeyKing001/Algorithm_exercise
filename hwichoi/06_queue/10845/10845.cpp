#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int>	Q;
	int	n;
	cin >> n;
	while (n--)
	{
		string	input;
		cin >> input;
		if (input == "push")
		{
			int	val;
			cin >> val;
			Q.push(val);
		}
		else if (input == "pop")
		{
			if (!Q.empty()) {
				cout << Q.front() << '\n';
				Q.pop();
			}
			else
				cout << "-1" << '\n';
		}
		else if (input == "size")
			cout << Q.size() << '\n';
		else if (input == "empty")
		{
			if (Q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "front")
		{
			if (!Q.empty())
				cout << Q.front() << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (input == "back")
		{
			if (!Q.empty())
				cout << Q.back() << '\n';
			else
				cout << "-1" << '\n';
		}
	}
	return (0);
}

