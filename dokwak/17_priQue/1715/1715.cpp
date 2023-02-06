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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum;
	cin >> n;
	priority_queue< int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}
//	cout << "init sum : " << sum << "\n";
	while(pq.size() != 1)
	{
		int temp1, temp2;
		temp1 = pq.top();
//		cout << "top() : " << temp1 << "\n";
		pq.pop();
		temp2 = pq.top();
//		cout << "top() : " << temp2 << "\n";
		pq.pop();
//		cout << "pushing : " << temp1+temp2 << "\n";
		sum += temp1 + temp2;
		pq.push(temp1 + temp2);
//		cout << "sum : " << sum << "\n";
	}
//	cout << pq.top() << "\n";
	cout << sum;
	return (0);
}

