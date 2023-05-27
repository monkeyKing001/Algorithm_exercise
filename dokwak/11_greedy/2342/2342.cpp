#include <iostream>
#include <algorithm>
using namespace std;

int d[100001][5][5];
const int inf = (int)1e9;

int mv[5][5] = {
	{0, 2, 2, 2, 2},
	{0, 1, 3, 4, 3},
	{0, 3, 1, 3, 4},
	{0, 4, 3, 1, 3},
	{0, 3, 4, 3, 1}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, j, k;
	for (i = 0; i <= 100000; i++)
		for (j = 0; j < 5; j++)
			for (k = 0; k < 5; k++)
				d[i][j][k] = inf;

	int cur = 0;
	d[0][0][0] = 0;

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++)
			{
				int left = d[cur][i][j] + mv[i][n];
				if (j != n && left < d[cur + 1][n][j])
					d[cur + 1][n][j] = left;

				int right = d[cur][i][j] + mv[j][n];
				if (i != n && right < d[cur + 1][i][n])
					d[cur + 1][i][n] = right;
			}
		}
		cur++;
	}
	
	int ans = inf;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			ans = min(ans, d[cur][i][j]);
	cout << ans;
}
