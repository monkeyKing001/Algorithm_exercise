#include <iostream>
using namespace std;
// 곱셈
#define ll long long

ll A, B, C;

int pow(ll p, ll q, ll m){ 
    if (q == 1) return p % m;
    ll l = pow(p, q/2, m);
    l = l * l % m;
    if (q%2 == 0) return l;
    else return l * p % m;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C;
    cout << pow(A, B, C);
    return 0;
}