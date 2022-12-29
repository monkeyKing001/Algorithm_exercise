#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	stack<int> s;
	cin >> n;
	while (n--)
	{
		int	i;
		cin >> i;
		if (i == 0)
		{
			if (!s.empty())
				s.pop();
		}
		else
			s.push(i);
	}
	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';
	return (0);
}

