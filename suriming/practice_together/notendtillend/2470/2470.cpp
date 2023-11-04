#include <iostream>
#include <algorithm>
using namespace std;
// 두 용액 
const int INF = 2000000001;

int N;
int arr[100001];
int ans0, ans1;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr+N);

    int minVal = INF;
    int en = N-1, st = 0;
    ans0 = arr[0]; ans1 = arr[en];
    while (st < en) {
        int p = arr[st]+arr[en];
        if (abs(p) < abs(minVal)) {
            minVal = p;
            ans0 = arr[st];
            ans1 = arr[en];
        }
        if (p < 0) {
            st ++;
        }
        else {
            en --;
        }
    }
    cout << ans0 << ' ' << ans1;
}