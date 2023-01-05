#include <iostream>
#include <stack>
using namespace std;
// 탑

#define pii pair<int, int>
#define F first
#define S second

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    stack<pii> st;
    cin >> N;
    FOR(N){
        int s, ans;
        cin >> s;
        if (st.empty()){
            ans = 0;
            cout << ans << ' ';
            st.push(make_pair(i, s));
        }
        else{
            while ((!st.empty()) and (st.top().S < s)){
                st.pop();
            }
            if (st.empty()){
                ans = 0;
                cout << ans << ' ';
            }  
            else{
                ans = st.top().F + 1;
                cout << ans << ' ';
            }
            st.push(make_pair(i, s));
        }
    }
}