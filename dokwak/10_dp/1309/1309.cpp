#include <bits/stdc++.h>
#define LION 1
#define NO_LION 0

using namespace std;
int n, m;
int mod = 9901;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> dp2(100001, 0);
	dp2[1] = 3;
	dp2[2] = 7;
	for (int i = 3; i < 100001; i++)
	{
			dp2[i] = 2 * dp2[i - 1] + dp2[i - 2];
			dp2[i] %= mod;
	}
	cout << dp2[n];
	return (0);
}

