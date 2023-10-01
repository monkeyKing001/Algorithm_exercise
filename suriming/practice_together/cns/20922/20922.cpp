#include <iostream>
#include <algorithm>
using namespace std;
// 겹치는 건 싫어

int N, K;
int arr[200001];
int cntarr[100001];
int ans = 0;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int l = 0;
    for (int r = 0; r < N; ++r){
        cntarr[arr[r]] ++;
        while(cntarr[arr[r]] > K){
            cntarr[arr[l]] --;
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}