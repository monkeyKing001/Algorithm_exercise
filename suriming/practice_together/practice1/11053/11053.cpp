#include <iostream>
using namespace std;
// 가장 긴 증가하는 부분 수열: O(N^2) 버전

int N;
int arr[1002];
int dp[1002];
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    dp[1] = 1;
    for (int i = 2; i <= N; ++i){
        int maxlen = 0;
        for (int j = i; j >= 1; --j){
            if (arr[j] < arr[i]) maxlen = max(maxlen, dp[j]);
        }
        dp[i] = maxlen+1;
        // ans = max(ans, dp[i]);
    }
    for (int i = 1; i <= N; ++i) ans = max(ans, dp[i]);
    cout << ans;
}   