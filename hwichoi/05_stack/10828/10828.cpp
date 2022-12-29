#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int	n;
	cin >> n;
	while (n--)
	{
		string c;
		cin >> c;
		if (c == "push")
		{
			int	t;
			cin >> t;
			s.push(t);
		}
		else if (c == "size")
			cout << s.size() << '\n';
		else if (c == "empty")
			cout << s.empty() << '\n';
		else if (c == "pop")
		{
			if (s.empty())
				cout << "-1" << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            }
            
		}
		else if (c == "top")
		{
			if (s.empty())
				cout << "-1" << '\n';
            else
                cout << s.top() << '\n';
		}
	}
	return (0);
}
