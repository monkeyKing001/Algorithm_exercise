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
int *arr;

void rec(int cur_i, int *buf)
{
	if (cur_i == m)
	{
		for (int i = 0; i < m; i++)
			cout << buf[i] << " "; 
		cout << "\n";
	}
	else 
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= buf[cur_i - 1])
			{
				buf[cur_i] = arr[i];
				rec(cur_i + 1, buf);
			}
			else {
				continue ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr, arr + n);
	int buf[10];
	for (int i = 0; i < n; i++)
	{
		buf[0] = arr[i];
		rec(1, buf);
	}
	return (0);
}

