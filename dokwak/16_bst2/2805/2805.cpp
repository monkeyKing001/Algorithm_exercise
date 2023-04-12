#include <bits/stdc++.h>

using namespace std;
int n;
long long trees[1000001];
long long need_to_take_tree_len;
long long get_max_height(long long need_to_take)
{
	long long min_h = 0;
	long long max_h = *max_element(trees, trees + n);
	long long mid_h = min_h + ((max_h - min_h) / 2);
	long long sol = mid_h;
	while (min_h <= max_h)
	{
		mid_h = min_h + ((max_h - min_h) / 2);
		long long taking = 0;
		for (int i = 0; i < n; i++)
			taking += max((long long)0, trees[i] - mid_h);
		if (taking >= need_to_take)
		{
			min_h = mid_h + 1;
			sol = mid_h;
		}
		else 
			max_h = mid_h - 1;
	}
	return (sol);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> need_to_take_tree_len;
	for (int i = 0; i < n; i++)
	{
		long long tree_len;
		cin >> tree_len;
		trees[i] = tree_len;
	}
	cout << get_max_height(need_to_take_tree_len);
	return (0);
}

