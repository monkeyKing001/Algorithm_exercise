#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	cin >> i;
	string a, b;
	while (i--)
	{
		vector<int> v(26, 0);
		cin >> a >> b;
		for (char c : a)
			v[static_cast<int>(c - 'a')]++;
		for (char c : b)
			v[static_cast<int>(c - 'a')]--;
		int flag = 0;
		for (int i : v) {
			if (i != 0) {
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "Impossible" << endl;
		else
			cout << "Possible" << endl;
	}
	return (0);
}

