#include <iostream>
using namespace std;
// 두 수의 합
// 시간복잡도 O(n+x)

int n, x;
int arr[2000001];
int ans;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        arr[t] = 1;
    }
    cin >> x;
    for (int i = 1; i < (x+1)/2; i++){
        if (arr[i] && arr[x-i]) ans += 1;
    }
    cout << ans;
}