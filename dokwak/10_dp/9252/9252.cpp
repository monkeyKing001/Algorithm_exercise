#include <bits/stdc++.h>

using namespace std;
int n, m;
int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string input1, input2;
  cin >> input1 >> input2;
	input1 = "0" + input1;
	input2 = "1" + input2;
  vector<vector<int>> dp(input2.size(), vector<int>(input1.size()));
  for (int i = 0; i < input2.size(); i++) {
    for (int j = 0; j < input1.size(); j++) {
      if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      if (input1[j] == input2[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  string LCS = "";
  cout << dp.back().back() << "\n";
  int i = input1.size() - 1, j = input2.size() - 1; 
  while (i >= 0 && j >= 0){
    if (input1[i] != input2[j]){
      if (i > 0 && dp[j][i] == dp[j][i - 1]) i--;
      else j--;
    }
    else LCS.push_back(max(input1[i--], input2[j--]));
  }
  string sol(LCS.rbegin(), LCS.rend());
  cout << sol;
	return (0);
}

