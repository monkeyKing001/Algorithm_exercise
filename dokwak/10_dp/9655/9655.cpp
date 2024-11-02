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
vector<int> dp(1001, -1);

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if (n % 2 == 0)
		cout << "CY";
	if (n % 2 == 1)
		cout << "SK";
	return (0);
}

