#include <bits/stdc++.h>
using namespace std;
int n;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int T = n;
  vector <int> dp(11, 0);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = (dp[1] + (dp[0] + 1));  //2
  dp[3] = (dp[2] + dp[1] + dp[0] + 1); //4
  for (int i = 4; i < 11; i++) 
    dp[i] = dp[i- 1] + dp[i - 2] + dp[i - 3];  
  for (int t_i = 0; t_i < T; t_i++) {
    int num;
    cin >> num;
    cout << dp[num] << "\n";
  }
	return (0);
}

