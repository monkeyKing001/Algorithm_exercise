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
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int k = m;
	int count = 0;
	priority_queue<int, vector<int>, greater<int>> pq(n, 1);
	while (pq.size() != k) {
		//peek 2 and add
		bool put_together = false;
		while (!put_together){
//			if (pq.size() < 2){
//				pq.push(1);
//			}
			int top = pq.top();
			pq.pop();
			int top_2nd = pq.top();
			pq.pop();
			if (top != top_2nd){
				pq.push(1);
				pq.push(top);
				pq.push(top_2nd);
				count++;
				continue;
			}
			pq.push(top + top_2nd);
			put_together = true;
		}
	}
	cout << count;
	return (0);
}

