#include <iostream>
using namespace std;
// Romantic Date

int T;
int arr[15][4]; // 
int ans;

void solve(){
    int availnum = 0;
    for (int i = 2; i < 15; ++i){
        for (int j = 0; j < 4; ++j){
            if (arr[i][j] == 0) availnum ++;
            if (arr[i][j] == 1 && availnum) {
                ans ++;
                availnum --;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; ++t){
        ans = 0;
        for (int i = 2; i < 15; ++i){
            for (int j = 0; j < 4; ++j){
                arr[i][j] = 0;
            }
        }
        for (int i = 0; i < 26; ++i){
            string s;
            cin >> s;
            int a = s[0]-'0';
            int b = s[1] - 'A';
            if (a >= 10) { // T(10): 36, J:26, Q:33, K:27, A: 17
                if (a == 36) a = 10;
                else if (a == 26) a = 11;
                else if (a == 33) a = 12;
                else if (a == 27) a = 13;
                else if (a == 17) a = 14;
            }
            // D:3, C:2, H:7, S:18
            if (b == 3) b = 0;
            else if (b == 2) b = 1;
            else if (b == 7) b = 2;
            else if (b == 18) b = 3;

            arr[a][b] = 1;
        }
        solve();
        cout << ans << '\n';
    }
}