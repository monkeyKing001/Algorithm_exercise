#include <iostream>
using namespace std;
// 부분수열의 합

int N, S;
int ans = 0;
int arr[21];

void bt(int cur, int tot){
    if (cur == N) {
        if (tot == S) ans += 1;
        return;
    }
    bt(cur+1, tot);
    bt(cur+1, tot+arr[cur]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> arr[i];
    bt(0, 0);
    if (S == 0) ans -= 1;
    cout << ans;
    return 0;
}