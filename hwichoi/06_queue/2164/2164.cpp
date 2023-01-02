#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int>	q;
	int	n;
	cin >> n;
	int	i;
	i = 1;
	while (n--)
	{
		q.push(i);
		i++;
	}
	while (q.size() > 1)
	{
		q.pop();
		if (q.size() > 1)
		{
			q.push(q.front());
			q.pop();
		}
	}
	cout << q.front() << '\n';
	return (0);
}

