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
	int T = 10;
	for (int t_i = 0; t_i < T; t_i++)
	{
		int n  = 0;
		cin >> n;
		int h[101];
		for (int i = 0; i < 101; i++)
		{
			h[i] = 0;
		}
		for (int i = 0; i < 100; i++)
		{
			int cur_h = 0;
			cin >> cur_h;
			h[cur_h]++;
		}
		int l = 1;
		int r = 100;
		while (h[l] == 0)
			l++;
		while (h[r] == 0)
			r--;
		while (n > 0 && l + 1 != r){
			h[l]--; h[l + 1]++; h[r]--; h[r - 1]++;
			if (h[l] == 0)
				l++;
			if (h[r] == 0)
				r--;
			n--;
		}
		cout << "#" << (t_i + 1) << " " << (r - l) <<"\n";
	}
	return (0);
}

