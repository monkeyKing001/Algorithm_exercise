#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
// 계단 오르기

int N;
int arr[302];
int dp[302];
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N ; ++i) cin >> arr[i];
    dp[1] = arr[1]; dp[2] = dp[1]+arr[2];
    dp[3] = max(dp[1]+arr[3], arr[2]+arr[3]);
    for (int i = 4; i <= N; ++i){
        dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
    }
    cout << dp[N];
}