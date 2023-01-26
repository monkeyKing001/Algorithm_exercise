#include <bits/stdc++.h>
using namespace std;

int main(void){
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arrInput;
        cin >> arrInput;
        int arrOut[n];
        int len;
        for (int j = 0; j < n; j++){
            char a;
            a = arrInput[j];
            if (a != '[' || a != ',' || a != ']'){
                arrOut[j] = a;
                len++;
            }
        }
        for (auto x: arrOut){
            cout << x << '\n';
        }

        // implemenation
        for (auto com: p){
            if (com == 'R'){
                int temp[len];
                for (int k = 0; k < len; k++){
                    temp[len-k] = arrOut[k];
                }
                for (int k = 0; k < len; k++){
                    arrOut[k] = temp[k];
                }
            }
            if (com == 'D'){
                if (len == 0) cout << "error";
                else {
                    for (int u = 1; u <= len; u++){
                        arrOut[i-1] = arrOut[i];
                    }
                    len --;
                }
            }
        }
    }
    
}