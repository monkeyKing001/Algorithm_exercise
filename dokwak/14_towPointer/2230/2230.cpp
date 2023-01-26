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
	int n;
	int m;
	vector <int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int min_gap;
	min_gap = INT_MAX;
	sort(v.begin(), v.end());
	int i, j = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (v[j] - v[i] >= m)
			{
				min_gap = min(min_gap, v[j] - v[i]);
//				cout << "j : " << j << "\n";
				break ;
			}
			if (v[j] - v[i] == m)
			{
				cout << min_gap << "\n";
				return (0);
			}
			j++;
		}
		i++;
	}
	cout << min_gap << "\n";
	return (0);
}
