#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N;
char c;
unordered_set<string> sset;

int ans; 

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> c;
    for (int i = 0; i < N; ++i){
        string s; 
        cin >> s;
        sset.insert(s);
    }
    int slen = sset.size();
    if (c == 'Y') ans = slen;
    else if (c == 'F') ans = slen/2;
    else ans = slen/3;
    cout << ans;
}