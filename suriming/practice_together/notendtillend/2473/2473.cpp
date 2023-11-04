#include <iostream>
#include <algorithm>
using namespace std;
// 세 용액
typedef long long ll;
const ll lINF = 3000000001;

int N;
int arr[5001];
int ans0, ans1, ans2;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr+N);
    ll minVal = lINF;
    for (int i = 0; i < N-2; ++i) { // N-3 N-2 N-1
        int st = i+1, en = N-1;
        while (st < en) {
            ll p = (ll) arr[i]+arr[st]+arr[en];
            if (abs(p) < minVal) {
                minVal = abs(p);
                ans0 = arr[i];
                ans1 = arr[st];
                ans2 = arr[en];
            }
            if (p < 0) st ++;
            else en --;
        }
    }
    cout << ans0 << ' ' << ans1 << ' ' << ans2; 
 }
