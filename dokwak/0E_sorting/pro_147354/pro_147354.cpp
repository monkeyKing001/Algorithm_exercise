#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int g_col = 2;
bool cmp(vector <int> a, vector <int> b)
{
	if (a[g_col - 1] == b[g_col - 1])
		return (a[0] > b[0]);
	else
		return (a[g_col - 1] < b[g_col - 1]);
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
	int r_b = row_begin - 1;
	int r_e = row_end - 1;
	g_col = col;
	sort(data.begin(), data.end(), cmp);
	int s_i[r_e - r_b + 1];
	for (int i = 0; i < r_e - r_b + 1; i++)
	{
		int sum = 0;
		for (int j = 0; j < data[r_b + i].size(); j++)
		{
			sum += data[r_b + i][j] % (r_b + i + 1);
//			cout << data[r_b + i][j] % (r_b + i + 1) << "\n";
		}
		s_i[i] = sum;
//		cout << "s_" << r_b + i << " = " << s_i[i] << "\n";
	}
	for (int i = 0; i < r_e - r_b + 1; i++)
	{
		answer = answer ^ s_i[i];
	}
    return answer;
}


int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector < vector <int> > data = {{2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}};
	sort(data.begin(), data.end(), cmp);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << "\n";
	}
	cout << solution(data, 2, 2, 3);
	return (0);
}

