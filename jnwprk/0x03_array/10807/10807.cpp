#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    int v;
    cin >> v;

    int res = 0;
    for (auto x: s){
        if (x == v) res++;
    }

    cout << res;
}