#include <iostream>
#include <algorithm>
using namespace std;
// 두 수의 합

int n, x;
int arr[100001];
int ans;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    sort(arr, arr+n);
    int st = 0, en = n-1;
    while(st < en){
        if (arr[st]+arr[en] == x){
            ans += 1;
            st += 1;
            en -= 1;
        }
        else if (arr[st]+arr[en] < x) st += 1;
        else en -= 1;
    }
    cout << ans;
}