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
	vector <int> steps(step_num + 1, 0);
	vector <int> score_of_step_s(step_num + 1, 0);
	vector <int> dp(step_num + 1, 0);
	for (int i = 1; i <= step_num; i++)
	{
		int score;
		cin >> score;
		score_of_step_s[i] = score;
	}
	dp[1] = score_of_step_s[1];
	dp[2] = score_of_step_s[1] + score_of_step_s[2];
	dp[3] = max(score_of_step_s[1], score_of_step_s[2]) + score_of_step_s[3];
	for (int j = 4; j <= step_num; j++)
		dp[j] = max(dp[j - 3] + score_of_step_s[j - 1], dp[j - 2]) + score_of_step_s[j];
	cout << dp[step_num];
	return (0);
}

