#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>

using namespace std;
vector <int> n_num(1000000, 0);
vector <int> dp(1000000, 0);
int sol = 0;

int find_num(vector <int> &dp, int part_k, int target_num)
{
	if (part_k == 1 && dp[target_num])
	{
		sol++;
		return target_num;
	}


}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s, k;
	int sol = 0;
	cin >> n >> s >> k;
	pair <int, int> dp_1;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		n_num.push_back(temp);
		dp[temp]++;
		cout << "dp[" << temp << "]++\n";
	}
	find_num(dp, k, s);
	sol
	return (0);
}

