#include <iostream>
#include <string>
using namespace std;
// 단어 공부 

int arr[26];
char ans = 'A';

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    // cout << 'A' - 'A' << ' ';
    // cout << 'a' - 'A' << ' ';
    // cout << 'Z' - 'A' << ' ';
    // cout << 'z' - 'A' << ' ';
    // cout << char(65);

    for (int i = 0; i < s.length(); ++i){
        // cout << s[i] - 'A' << ' ';
        if (s[i]-'A' >= 32) arr[s[i]-'A'-32] ++;
        else arr[s[i]-'A'] ++;
    }

    int maxval = -1;
    int maxcnt = 1;

    for (int i = 0; i < 26; ++i){
        // cout << arr[i];
        
        if (arr[i] > 0 && arr[i] == maxval) {
            // ans = '?';
            // break;
            maxcnt ++;
        }

        if (arr[i] > maxval) {
            maxval = arr[i];
            ans = char(i+'A');
            maxcnt = 1;
            // cout << i;
        }
    }   
    if (maxcnt > 1) ans = '?';
    cout << ans << '\n';
}