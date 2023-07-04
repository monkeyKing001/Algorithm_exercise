#include <iostream>
using namespace std;
// 2*n 타일링 2

int n;
int dp[1001];
int mod = 10007;

int main(void){
    cin >> n;
    dp[1] = 1; dp[2] = 3;
    for (int i = 3; i <= n; i++) dp[i] = (dp[i-1]+dp[i-2]*2)%mod;
    cout << dp[n];
}