#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    string s;
    s = '*';
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << '*';
        }
        cout << '\n';
    }
}