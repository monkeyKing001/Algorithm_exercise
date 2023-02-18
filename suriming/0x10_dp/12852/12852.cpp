#include <iostream>
using namespace std;
// 1로 만들기 2

int N;
int dp[1000002];
int arr[1000002];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    dp[1] = 0;
    for (int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + 1;
        arr[i] = i-1;
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            arr[i] = i/2;
        }
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            arr[i] = i/3;
        }
    }
    cout << dp[N] << '\n';
    int cur = N;
    while(true){
        cout << cur << ' ';
        if (cur == 1) break;
        cur = arr[cur];
    }
}