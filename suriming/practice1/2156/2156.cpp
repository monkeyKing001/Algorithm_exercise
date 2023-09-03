#include <iostream>
using namespace std;
// 포도주 시식

int n;
int arr[10001];
int dp[10001];

int main(void){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];
    dp[2] = max(dp[1], max(arr[0]+arr[2], arr[1]+arr[2]));
    for (int i = 2; i < n; ++i){
        int nodrink = dp[i-1];
        int a = dp[i-2]+arr[i]; // i-1 번째 포도주 안마시기
        int b = dp[i-3]+arr[i-1]+arr[i]; // i-2번째 포도주 안마시기
        int drink = max(a, b);
        dp[i] = max(nodrink, drink);
    }
    cout << dp[n-1];
}