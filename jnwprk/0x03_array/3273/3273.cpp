#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // size of seq
    int n;
    cin >> n;

    // seq
    int s[n];
    for (int i = 0; i < n; i++) cin >> s[i];

    // sum of the two elements of the seq
    int x;
    cin >> x;

    // result holder
    bool res[2000001] = {false};
    int final = 0;

    // iteration
    for (auto a: s){
        if (res[a]){
            final++;
        }
        if(x-a > 0){
            res[a] = true;
            res[x-a] = true;
        }
    }
    cout << final;
}