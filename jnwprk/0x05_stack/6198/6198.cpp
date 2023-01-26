#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        int h; cin >> h;
        arr[i] = h;
    }

    stack<pair<int,int>> S;
    S.push({1e+9, N});
    long long ans = 0;
    bool check = false;
    for (int j = N-1; j >= 0; j--){
        check = false;
        while(S.top().X < arr[j]){
            S.pop();
            check = true;
        }
        if (check) ans += S.top().Y-j-1;
        S.push({arr[j], j});
    }
    cout << ans;
}