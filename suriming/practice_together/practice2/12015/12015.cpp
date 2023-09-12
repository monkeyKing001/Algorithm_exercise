#include <iostream>
using namespace std;
// 가장 긴 증가하는 부분 수열2

int N;
int arr[1000001];
int dp[1000001];
int X[1000001];
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    cin >> arr[1]; dp[1] = 1; X[1] = arr[1];
    ans = 1;
    for (int i = 2; i <= N; ++i) {
        cin >> arr[i];
        if (arr[i] > X[ans]) {
            X[++ans] = arr[i];
            dp[i] = ans;
        }
        else {
            int l = 1, r = ans;
            while (l < r){
                int mid = (l+r)/2;
                if (arr[i] > X[mid]) l = mid+1;
                else r = mid;
            }
            X[l] = arr[i];
            dp[i] = l;
        }
    }
    cout << ans;
}