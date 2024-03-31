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
int sol = 0;

void rev(vector<vector<int>> &arr, int start_i, int start_j){
	for (int i = start_i; i < start_i + 3; i++) {
		for (int j = start_j; j < start_j + 3; j++) {
			arr[i][j] = arr[i][j] == 1 ? 0 : 1;
		}
	}
	sol++;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> matrix(n);
	vector<vector<int>> ansMatrix(n);
	for (int i = 0; i < n; i++) {
		matrix[i] = vector<int>(m, 0);
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			matrix[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		ansMatrix[i] = vector<int>(m, 0);
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			ansMatrix[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (matrix[i][j] != ansMatrix[i][j])
				rev(matrix, i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != ansMatrix[i][j]){
				sol = -1;
			}
		}
	}
	cout << sol;
	return (0);
}
