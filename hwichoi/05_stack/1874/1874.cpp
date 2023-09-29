#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <list>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;
	list<char>	list;
	auto	cursor = list.end();
	while (n--)
	{
		char	input;
		cin >> input;
		if (input == '<') {
			if (cursor != list.begin())
				cursor--;
		}
		else if (input == '>') {
			if (cursor != list.end())
				cursor++;
		}
		else if (input == '-') {
			if (!list.empty()) {
				cursor--;
				cursor = list.erase(cursor);
			}
		}
		else
			list.insert(cursor, input);
	}
	for (auto t : list) cout << t;
	cout << '\n';
	return (0);
}

