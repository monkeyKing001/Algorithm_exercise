#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <stack>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	string input;
	cin >> input;
	char prev = 0;
	int cnt = 0;
	for (char c : input) {
		if (c == '(')
			s.push(c);
		else {
			s.pop();
			if (prev == '(')
				cnt += s.size();
			else
				++cnt;
		}
		prev = c;
	}
	cout << cnt << endl;
	return (0);
}

