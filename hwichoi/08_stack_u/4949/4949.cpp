#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string	s;
	getline(cin, s);
	while (s != ".")
	{
		int	no = 0;
		stack<char> a;
		for (char c : s)
		{
			if (c == '(' || c == '[')
				a.push(c);
			else if (c == ')')
			{
				if (a.empty() || a.top() != '(') {
					no = 1;
					break;
				}
				else
					a.pop();
			}
			else if (c == ']')
			{
				if (a.empty() || a.top() != '[') {
					no = 1;
					break;
				}
				else
					a.pop();
			}
		}
		if (!a.empty())
			no = 1;
		if (no)
			cout << "no\n";
		else
			cout << "yes\n";
		getline(cin, s);
	}
	return (0);
}

