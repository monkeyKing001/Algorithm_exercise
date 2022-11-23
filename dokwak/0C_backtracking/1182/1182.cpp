#include <bits/stdc++.h>
using namespace std;
int	n, s;
int	max_com;
int	num = 0;
int get_sum(vector <int> set, int comb)
{
	int	sum = 0;
	for (int i = 0; i < n; i++)
		int idx = comb;
	return (sum);
}

void subset_sum(vector <int> set, int comb)
{
	for (int i = 0; i < max_com; i++)
	{
		if (get_sum(set, i) == s)
			num++;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	vector <int> set;
	max_com = 1 << n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		set.push_back(temp);
	}
	subset_sum(set, 0);
	cout << num;
	return (0);
}
