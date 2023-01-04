#include<iostream>
#include<list>
using namespace std;

#define pb push_back
#define pf push_front
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; 
    cin >> T;
    while (T--){
        string s;
        list<char> cl;
        cin >> s;
        auto cursor = cl.end();
        FOR(sz(s)){
            if (s[i] == '<'){
                if (cursor != cl.begin()) cursor --;
            }
            else if (s[i] == '>'){
                if (cursor != cl.end()) cursor ++;
            }
            else if (s[i] == '-'){
                if (cursor != cl.begin()) {
                    cursor --;
                    cursor = cl.erase(cursor);
                }
            }
            else {
                cl.insert(cursor, s[i]);
            }
        }
        EACH(i, cl) cout << i;
        cout << "\n";
    }
    return 0;
}