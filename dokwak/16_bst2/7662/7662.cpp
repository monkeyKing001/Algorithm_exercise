#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <set>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		multiset<int> s;
		int m, M;
		M = INT_MAX;
		m = INT_MIN;
		for (int j = 0; j < t; j++)
		{
			string 	cmd;
			int		val;
			cin >> cmd;;
			cin >> val;
			if (cmd == "I")
			{
				s.insert(val);
				m = min(m, val);
				M = max(M, val);
			}
			else if(cmd == "D")
			{
				if (val == -1 && s.size() != 0)//erase min
					s.erase(s.begin());
				else if (val == 1 && s.size() != 0)
					s.erase(prev(s.end()));
					//s.erase(--s.end());
			}
		}
		if (s.size() != 0)
			cout << *--s.end() << " " << *(s.begin()) << "\n";
		else
			cout << "EMPTY\n";
	}
	return (0);
}

