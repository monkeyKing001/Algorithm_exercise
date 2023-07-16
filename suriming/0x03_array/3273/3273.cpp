#include <iostream>
using namespace std;
// 두 수의 합
// 시간복잡도 O(n)
int n, x;
int arr[100001];
int IsOccured[1000001];
int ans;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    for (int i = 0; i < n; i++){
        if (x-arr[i] < 1000000 && arr[i] < x && IsOccured[x-arr[i]]) ans += 1;
        IsOccured[arr[i]] = 1;
    }
    cout << ans;
}