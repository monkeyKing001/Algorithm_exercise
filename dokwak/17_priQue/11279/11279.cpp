#include <queue>
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
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 0)
		{
			if (pq.size())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << "0\n";
			}
		}
		else {
			pq.push(cmd);
		}
	}
	return (0);
}

