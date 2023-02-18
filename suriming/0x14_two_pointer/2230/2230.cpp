#include <iostream>
#include <algorithm>
using namespace std;
// 수 고르기

int N, M;
int arr[100001];
int mn = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int en = 0;
    for (int st = 0; st < N; st++){
        while(en < N && arr[en]-arr[st] < M) en += 1;
        if (en == N) break;
        mn = min(mn, arr[en] - arr[st]);
    }
    cout << mn;
}
