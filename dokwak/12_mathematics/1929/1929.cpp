#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

long long n, m;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector <bool> screen(m + 10, false);
	screen[1] = true;
	for (long long i = 2; i <= m; i++)
	{
		//find start
		if (screen[i] == true)
			continue ;
		for (long long j = i; i * j <= m; j++)
			screen[i * j] = true;
	}
	for (long long i = n; i <= m; i++)
	{
		if (screen[i] == false)
			cout << i << "\n";
	}

	return (0);
}

