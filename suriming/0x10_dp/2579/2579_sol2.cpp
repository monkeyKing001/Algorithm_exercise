#include <iostream>
using namespace std;
//계단오르기

int N;
int stair[301];
int dp[301];
int tot = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> stair[i];
        tot += stair[i];
    }
    dp[1] = stair[1];
    dp[2] = stair[2];
    dp[3] = stair[3];
    for (int i=4; i<=N; i++){
        dp[i] = min(dp[i-2], dp[i-3]) + stair[i];
    }
    cout << tot - min(dp[N-1], dp[N-2]);
    return 0;
}