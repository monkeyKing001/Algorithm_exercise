//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
using namespace std;
int n;

int make_one(int index, vector <int> &num)
{
	if (num[index] != INT_MAX)
		return (num[index]);
	//cout << "index : " << index << "\n";
	if (index == 1)
		num[index] = 0;
	else
	{
		if (index % 3 == 0)
			num[index] = min(num[index], make_one(index / 3, num) + 1);
		if (index % 2 == 0)
			num[index] = min(num[index], make_one(index / 2, num) + 1);
		num[index] = min(num[index], make_one(index - 1, num) + 1);
	}
	//cout << "updated vec[" << index << "] : " << num[index] << endl;
	return (num[index]);
}


int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	vector <int> num(n + 1, INT_MAX);
//	cout << INT_MAX << endl;;
//	cout << num[n] << endl;;
	int sol = make_one(n, num);
	cout << sol;
	return (0);
}

