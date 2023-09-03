#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int dur[10];
int wei[10];
int cnt;
int ret;

void recur(int dep) {
	if (dep == n) {
		if (cnt > ret) ret = cnt;
		return;
	}
	if (dur[dep] <= 0) {
		recur(dep+1);
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (i == dep || dur[i] <= 0) {
			tmp++;
			continue;
		}
		dur[i] -= wei[dep];
		dur[dep] -= wei[i];
		cnt += (dur[i] <= 0) + (dur[dep] <= 0);
		recur(dep+1);
		cnt -= (dur[i] <= 0) + (dur[dep] <= 0);
		dur[i] += wei[dep];
		dur[dep] += wei[i];
	}
	if (tmp == n) recur(dep+1);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> dur[i] >> wei[i];
	recur(0);
	cout << ret << '\n';
	return (0);
}

