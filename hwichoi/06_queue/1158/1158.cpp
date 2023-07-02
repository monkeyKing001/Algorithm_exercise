#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	vector<int> v;
	while (!q.empty()) {
		for (int i = 0; i < k - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}
	cout << "<" << v[0];
	for (int i = 1; i < v.size(); ++i)
		cout << ", " << v[i];
	cout << ">" << endl;
	return (0);
}

