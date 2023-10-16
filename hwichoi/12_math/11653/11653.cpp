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
	cout.tie(0);
	cin >> n;
	vector<int> res;
	int i = 2;
	while (n != 1) {
		if (n % i == 0) {
			n /= i;
			res.push_back(i);
		}
		else i++;
		if (i*i > n) {
			if (n != 1) res.push_back(n);
			break;
		}
	}
	for (int i : res)
		cout << i << '\n';
	return (0);
}

