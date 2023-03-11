#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int tower[500001];
	int rec[500001];
	stack <int> s;
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> tower[i];
	for (int i = 0; i < n; i++)
	{
		int h = tower[n - i - 1];
		rec[n - i - 1] = 0;
		while (s.size() && tower[s.top()] < h)
		{
			rec[s.top()] = n - i;
			s.pop();
		}
		s.push(n - i - 1);
	}
	for (int i = 0; i < n; i++)
		cout << rec[i] <<  " ";
	return (0);
}
