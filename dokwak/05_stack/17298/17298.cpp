#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	stack<int> s;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> ans(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
		if (!s.empty())
			ans[i] = s.top();
		s.push(arr[i]);
	}
	for (auto a : ans) cout << a << " ";
	return (0);
}

