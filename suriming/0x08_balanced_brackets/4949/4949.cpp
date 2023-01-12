#include<iostream>
#include<stack>
#include<string>
using namespace std;

#define vt vector
#define ll long long
#define pb push_back
#define pf push_front
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define en '\n'
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

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (true){
        string s;
        stack<char> st;
        getline(cin, s);
        // printf("DDDSFdf");
        if (s == ".") break;
        int isBalanced = 1;
        EACH(e, s){
            if (e == '[' or e == '(') st.push(e); 
            else if (e == ']') {
                if (!st.empty() and st.top() == '[') st.pop();
                else {
                    isBalanced = 0;
                    break;
                }
            }
            else if ( e == ')') {
                if (!st.empty() and st.top() == '(') st.pop();
                else {
                    isBalanced = 0;
                    break;
                }
            }
        }  
        if (!st.empty()) isBalanced = 0;
        if (isBalanced) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}