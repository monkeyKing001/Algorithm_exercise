#include <iostream>
using namespace std;
#define ll long long

ll X, Y;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> X >> Y;
    int diff = Y-X;
    if (diff == 0) {
        cout << 0;
        return 0;
    }
    ll n = 1;
    while(n*(n+1) < diff) n++;
    ans = 2*n;
    if (n*n >= Y-X) ans --;
    cout << ans;
    return 0;
}