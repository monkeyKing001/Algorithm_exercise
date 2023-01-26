#include <bits/stdc++.h>
using namespace std;

int main(void){
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++){
        bool isPrime;
        isPrime = false;
        for (int r = 2; r*r <= i; r++){
            if (i == 2){
                isPrime = true;
                break;
            }
            else if (i % r == 0 || i == 1) {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true) cout << i << '\n';
    }    
}