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
int need_painted[200001];

int solution(int n, int m, vector <int> section)
{
	int answer = 0;
	for (int i = 0; i < section.size(); i++)
	{
		int sec_i = section[i];
		need_painted[sec_i] = 1;
	}
	for (int i = 0; i < section.size(); i++)
	{
		int sec_i = section[i];
		if (need_painted[sec_i] == 0)
			continue;
		for (int j = 0; j < m; j++)
			need_painted[sec_i + j] = 0;
		answer++;
	}
	return (answer);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	n = 4;
	m = 1;
	vector <int> test = {1, 2, 3, 4};
	cout << solution(n, m, test);
	return (0);
}

