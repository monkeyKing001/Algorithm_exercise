#include <iostream>
using namespace std;
// 이친수

#define ll long long

int N;
ll dp[91][2]; // 0으로 끝나는 거 , 1로 끝나는 거
  
int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N;
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;
    dp[3][0] = dp[2][0]+dp[2][1]; dp[3][1] = dp[2][0];
    for (int i = 3; i <= N; i++){
        dp[i][0] = dp[i-1][0]+dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[N][0]+dp[N][1];
}