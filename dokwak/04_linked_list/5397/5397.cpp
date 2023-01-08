#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <deque>
#include <string>
#include <iterator>

using namespace std;

int	main(int argc, char **argv)
{
	std::deque<char> passwd;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << n;
	for (int i = 0; i < n; i++)
	{
		std::string in;
		cin >> in;
		int current_cursor = 0;
		cout << in;
		auto iter = (passwd.begin() + current_cursor);
		for (int j = 0; j < in.length(); j++)
		{
		iter = (passwd.begin() + current_cursor);
		cout << *iter;
			switch (in[j]) {
				//move cursor left
				case '<':
					if (current_cursor > 0)
						j--;
					break;
				//move cursor right
				case '>':
					if (current_cursor < passwd.size())
						j++;
					break;
				//erase
				case '-':
					passwd.erase(iter);
					break;
				//char
				default:
					iter = (passwd.begin() + current_cursor);
					passwd.insert(iter, in[j]);
					break;
					
			}
		}
	}
	for (auto wd = passwd.begin(); wd != passwd.end(); wd++) {
		cout << *wd;
	}
	return (0);
}

