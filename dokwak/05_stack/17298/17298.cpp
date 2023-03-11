#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, temp_max;
int arr[1000001];
int okun[1000001];
stack <int> s;
int mem;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		int num, r_num;
		num = arr[i];
		okun[i] = -1;
		if (i != n - 1)
			r_num = arr[i + 1];
		if (num < r_num)
			okun[i] = r_num;
		while (s.size() && arr[s.top()] < num)
		{
			int find_okun = s.top();
			s.pop();
			okun[find_okun] = num;
		}
		s.push(i);
	}
	okun[n-1] = -1;
	int i = -1;
	while (++i < n)
	{
		cout << okun[i];
		if (i != n - 1)
			cout << " ";
	}
	return (0);
}

