#include <ios>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int left_sol;
int pro_n;
int cur_alp;
int cur_cop;

int solution(int alp, int cop, vector<vector<int>> problems) 
{
	int anw;
	int p[151][151];
	cur_alp = alp;
	cur_cop = cop;
	p[cur_alp][cur_cop] = 0;
	for (int i = cur_alp; i < 151; i++)
	{
		for (int j = cur_cop; j < 151; j++)
		{
		}
	}
	return (anw);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> cur_alp >> cur_cop;
	int n;
	cin >> n;
	vector<vector <int>> problems;
	for (int i = 0; i < n; i++)
	{
		vector <int> temp;
		for (int j = 0; j < 5; j++)
		{
			int temp_input;
			cin >> temp_input;
			temp.push_back(temp_input);
		}
		problems.push_back(temp);
	}
	return (0);
}

