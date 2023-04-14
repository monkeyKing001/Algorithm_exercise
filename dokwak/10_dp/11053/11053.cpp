#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector <int> input;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (input.size() != 0 && input[input.size() - 1] >= temp)
		{
			vector <int>::iterator it = lower_bound(input.begin(), input.end(), temp);
			*it = temp;
		}
		else
			input.push_back(temp);
	}
	cout << input.size();

	return (0);
}

