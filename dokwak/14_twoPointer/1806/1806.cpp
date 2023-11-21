#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

bool cmp(int i, int j)
{
	return (j < i);
}

int	main(int argc, char **argv)
{
	int n, s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int len = INT_MAX;
//	for (int i = 0; i < n; i++)
//		cout << v[i] << " ";
	int i = 0;
	int j = i;
	long long temp_sum = v[i];
	while (i < n)
	{
		if (i > j)
		{
			temp_sum = v[i];
			j = i;
		}
		while (temp_sum < s && ++j < n)
			temp_sum += v[j];
		if (temp_sum >= s)
		{
			len = min(j - i + 1, len);
//			cout << "len : " << len << " i, j : "<< i <<", "<< j << "\n";
		}
		temp_sum -= v[i];
		i++;
	}
	if (len != INT_MAX)
		cout << len;
	else
		cout << "0";
	return (0);
}

