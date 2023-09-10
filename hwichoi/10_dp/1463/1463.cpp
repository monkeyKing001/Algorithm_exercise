#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
int n;
int d[1000002];
queue<int> Q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur%3 == 0 && !d[cur/3]) {
			d[cur/3] = d[cur]+1;
			Q.push(cur/3);
		}
		if (cur%2 == 0 && !d[cur/2]) {
			d[cur/2] = d[cur]+1;
			Q.push(cur/2);
		}
		if (cur > 1 && !d[cur-1]) {
			d[cur-1] = d[cur]+1;
			Q.push(cur-1);
		}
	}
	cout << d[1] << '\n';
	return (0);
}

