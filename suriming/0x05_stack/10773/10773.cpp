#include <iostream>
#include <stack>
using namespace std;
//제로

#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

int main(){
    int K;
    cin >> K;
    stack<int> S;
    while (K--){
        int n;
        cin >> n;
        if (n == 0) S.pop();
        else S.push(n);
    } 
    int ans = 0;
    while (sz(S)) {
        ans += S.top(); 
        S.pop();
    }
    cout << ans << '\n';
    return 0;
}