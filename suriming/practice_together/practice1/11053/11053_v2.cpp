#include <iostream>
using namespace std;
// 가장 긴 증가하는 부분 수열: O(NlogN) 버전

int N;
int arr[1002];
int dp[1002];
int X[1002];
int ans = 1;

int main(void){
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    dp[1] = 1; X[1] = arr[1];
    for (int i = 2; i <= N; ++i){
        int l = 1, r = ans;
        if (X[ans] < arr[i]){
            X[++ans] = arr[i];
            dp[i] = ans;
        }
        else{
            int l = 1, r = ans;
            while (l < r){
                int mid = (l+r)/2;
                if (X[mid] < arr[i]) l = mid+1;
                else r = mid;
            }
            X[l] = arr[i];
            dp[i] = l;
        }
    }
    cout << ans;
}