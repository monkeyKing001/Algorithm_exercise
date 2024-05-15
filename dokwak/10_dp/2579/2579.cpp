#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int step_num;
	cin >> step_num;
	vector <int> steps(step_num, 0);
	vector <int> score_of_step_s(step_num, 0);
	vector <int> dp(step_num, 0);
	for (int i = 0; i < step_num; i++) 
		cin >> steps[i];
	dp[0] = steps[0];
	dp[1] = steps[1] + dp[0];
	dp[2] = max(0 + steps[1], steps[0]) + steps[2];
	//max
	//1 -> jump 2 steps
	//2 -> jump 1 step(should be 1 prev is from 3 prev)
	for (int i = 3; i < step_num; i++) 
		dp[i] = max(dp[i - 2], dp[i - 3] + steps[i - 1]) + steps[i];
	cout << dp[step_num - 1];
	return (0);
}

