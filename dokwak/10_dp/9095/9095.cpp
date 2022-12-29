#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> way(12, 0);
	way[1] = 1;
	way[2] = 2;
	way[3] = 4;
	for (int i = 4; i < 12; i++)
		way[i] = way[i - 1] + way[i - 2] + way[i - 3];
	for (int i = 0; i < n; i ++)
	{
		int out;
		cin >> out;
		cout << way[out] << "\n";
	}
	return (0);
}

