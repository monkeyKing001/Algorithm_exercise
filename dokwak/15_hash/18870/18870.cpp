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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	set<int> coor;
	map<int, int> zip;
	int count = 0;
	vector<int> arr(n + 1);
	for (int i = 0; i < n; i++)
	{
		int org_cor;
		cin >> org_cor;
		coor.insert(org_cor);
		arr[i] = org_cor;
	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << "\n";
	set<int>::iterator it = coor.begin();
	for (; it != coor.end(); it++)
	{
		zip.insert(make_pair(*it, count++));
	}
	for (int i = 0; i < n; i++)
	{
		int org = arr[i];
		arr[i] = zip[org];
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return (0);
}

