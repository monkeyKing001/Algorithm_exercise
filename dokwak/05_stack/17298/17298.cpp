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
	for (int i = 0; i + 1 < n; i++)
	{
		int num, r_num;
		if (r_num > num)
			okun[i] = r_num;
		else 
			s.push(i);
	}
	return (0);
}

