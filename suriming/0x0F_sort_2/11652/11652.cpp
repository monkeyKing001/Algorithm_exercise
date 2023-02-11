#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long arr[100001];

long long ans;
int cnt = 1;
int mxcnt = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    ans = arr[0];
    arr[N] = 0x3f3f3f3f3f3f3f3f;
    for (int i=1; i<=N; i++){
        if (arr[i-1] == arr[i]) cnt += 1;
        else{
            if (cnt > mxcnt){
                mxcnt = cnt;
                ans = arr[i-1];
            }
            cnt = 1;
        }
    }
    cout << ans;
    return 0;
}