#include <iostream>
#include <algorithm>
using namespace std;
// 부분합

const int INF = 0x3f3f3f3f;

int N, S;
int arr[100001];
int mn = INF;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int tot = arr[0];
    int en = 0;
    for (int st = 0; st < N; st++){
        while(en < N && tot < S){
            en += 1;
            // N까지 오면 못 찾은 것이므로
            if (en != N) tot += arr[en];
        }
        if (en == N) break; // 못찾음
        mn = min(mn, en-st+1);
        tot -= arr[st];
    }
    if (mn == INF) mn = 0;
    cout << mn;
}
