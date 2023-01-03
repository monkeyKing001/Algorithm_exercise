#include <bits/stdc++.h>
using namespace std;

int freq_a[26], freq_b[26];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    
    for (auto x: a){
        freq_a[x-'a']++;
    }
    for (auto y: b){
        freq_b[y-'a']++;
    }

    int result = 0;
    for (int i = 0; i < 26; i++){
        result += abs(freq_a[i] - freq_b[i]);
    }
    cout << result;
}