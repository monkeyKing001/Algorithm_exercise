#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n[9];
    for (int i = 0; i < 9; i++) cin >> n[i];

    int m;
    int idx;
    m = 0;
    idx = 0;
    for (int j = 0; j < 9; j++){
        if (m < n[j]){
            m = n[j];
            idx = j;
        }
    }
    cout << m << '\n';
    cout << idx + 1;
}