#include <bits/stdc++.h>

using namespace std;
long long n, k;
long long lines[10001];
int max_len(long long target)
{
	long long min_len = 1;
	long long max_len = INT_MAX;
	//long long max_len = *max_element(lines, lines + n);
	long long mid_len = min_len + ((max_len - min_len) / 2);
	long long total_div_lines = 0;;
	long long sol = mid_len;
	while (min_len <= max_len)
	{
		total_div_lines = 0;
		mid_len = min_len + ((max_len - min_len) / 2);
		for (int i = 0; i < n; i++)
			total_div_lines += lines[i] / mid_len;
		//fail
		if (total_div_lines < target)
			max_len = mid_len - 1;
		//success
		else if (total_div_lines >= target)
		{
			sol = mid_len;
			min_len = mid_len + 1;
		}
		total_div_lines = 0;
//		cout << "max, min : " << max_len << ", " << min_len << "\n";
//		cout << "now mid is " << mid_len << "\n";
	}
	return (sol);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		long long line_len;
		cin >> line_len;
		lines[i] = line_len;
	}
	cout << max_len(k);
	return (0);
}
