#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <vector>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(26, 0);
	string a, b;
	cin >> a;
	cin >> b;
	for (char c : a)
	{
		v[static_cast<int>(c - 'a')]++;
	}
	for (char c : b)
		v[static_cast<int>(c - 'a')]--;
	int cnt = 0;
	for (int i : v)
	{
		if (i != 0)
			cnt += abs(i);
	}
	cout << cnt << endl;
	return (0);
}

