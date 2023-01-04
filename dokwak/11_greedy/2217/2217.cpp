#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>

using namespace std;
long long n, max_weight;

bool comp(int r1, int r2)
{
	return (r2 < r1);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> ropes (n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int weight;
		cin >> weight;
		ropes[i] = weight;
	}
	sort(ropes.begin(), ropes.end(), comp);
//	for (int i = 0; i < n; ++i)
//		cout << ropes[i] << endl;
	for (int i = 0; i < n; i++)
	{
		long long temp_max = ropes[i] * (i + 1);
		max_weight = max(max_weight, temp_max);
		//cout << "max_weight = " << max_weight << endl;
	}
	cout << max_weight;

	return (0);
}

