#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    // exceptions
    if (a > b) swap(a, b);

    if (a == b || b - a == 1){
        cout << 0;
    }
    else{
        // first output
        cout << b - a - 1 << '\n';
        // second output
        for (long long i = a + 1; i < b; i++) cout << i << ' ';
    }
}