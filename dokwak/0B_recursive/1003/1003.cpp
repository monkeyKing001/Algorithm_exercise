#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;
int fib_n_z[45];
int fib_n_o[45];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < 45; i++)
	{
		if (i == 0)
		{
			fib_n_z[i] = 1;
			fib_n_o[i] = 0;
		}
		else if (i == 1)
		{
			fib_n_z[i] = 0;
			fib_n_o[i] = 1;
		}
		else
		{
			fib_n_z[i] = fib_n_z[i - 1] + fib_n_z[i - 2];
			fib_n_o[i] = fib_n_o[i - 1] + fib_n_o[i - 2];
		}
	}
	for (int t_i = 0; t_i < T; t_i++)
	{
		cin >> n;
		cout << fib_n_z[n] << " " << fib_n_o[n] << "\n";
	}
	return (0);
}
