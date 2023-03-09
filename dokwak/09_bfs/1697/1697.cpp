#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int visited[100001];
queue <int> q;

int n, k;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int subin, sister;
	subin  = n;
	sister = k;
	visited[subin] = 1;
	q.push(n);
	while (!q.empty())
	{
		subin = q.front();
		int step = visited[subin];
		q.pop();
		if (subin == sister)
		{
			cout << step - 1;
			return (0);
		}
		for (int i = 0; i < 3; i++)
		{
			int next_subin;
			if (i == 0)
				next_subin = subin + 1;
			else if (i == 1)
				next_subin = subin - 1;
			else
				next_subin = subin * 2;
			int next_step = step + 1;
			if (next_subin < 0 || next_subin > 100000 || visited[next_subin])
				continue ;
			q.push(next_subin);
			visited[next_subin] = next_step;
		}
	}
	return (0);
}
