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
long long mod = 1000000007;
void mult_mat(long long (&a)[2][2], long long (&b)[2][2])
{
	long long temp_a[2][2];
	long long temp_b[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp_a[i][j] = a[i][j];
			temp_b[i][j] = b[i][j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j] = (temp_a[i][0] * temp_b[0][j]) + (temp_a[i][1] * temp_b[1][j]);
			a[i][j] %= mod;
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long input;
	cin >> input;
	long long e[2][2]= {{1, 0}, {0, 1}};
	long long a[2][2] = {{1, 1}, {1, 0}};
	while (input > 0)
	{
		if (input % 2 == 1)
			mult_mat(e, a);
		mult_mat(a, a);
		input /= 2;
	}
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << e[i][j] << "\t";
//		}
//		cout << "\n";
//	}

	cout << e[0][1];
	return (0);
}
