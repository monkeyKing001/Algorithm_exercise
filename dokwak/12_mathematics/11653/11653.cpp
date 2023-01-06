#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int n;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n == 1)
		return (0);
	int i = 2;
	while (i * i <= n)
	{
		while (n % i == 0)
		{
			cout << i << "\n";
			n = n / i;
		}
		i++;
	}
	if (n != 1)
		cout << n;
	return (0);
}

