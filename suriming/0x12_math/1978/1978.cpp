#include <iostream>
using namespace std;
//소수 찾기

int N = 0;
int ans = 0;

bool isprime(int x){
    if (x == 1) return 0;
    for (int i=2; i*i<=x; i++){
        if (x%i==0) return 0;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while (N--){
        int k;
        cin >> k;
        ans += isprime(k);
    }
    cout << ans;
}