#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int k;
stack <int> s;
int sol;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0 && !s.empty())
		{
			sol -= s.top();
			s.pop();
		}
		else {
			s.push(temp);
			sol+= temp;
		}
	}
	cout << sol;
	return (0);
}

