#include <iostream>
using namespace std;
//Z
int N, r, c;

int z(int l, int p, int q){
    if (l == 0) return 0;
    int half = 1<<(l-1);
    if (p < half && q < half) return z(l-1, p, q);
    else if (p < half && q >= half) return half*half + z(l-1, p, q-half);
    else if (p >= half && q < half) return 2*half*half + z(l-1, p-half, q);
    else return 3*half*half + z(l-1, p-half, q-half);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> r >> c;
    cout << z(N, r, c);
    return 0;
}