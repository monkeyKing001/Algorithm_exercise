#include <iostream>
#include <queue>
using namespace std;
//카드2

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    queue<int> q;
    cin >> N;
    FOR(N) q.push(i+1);
    int flag = 0;
    while (q.size() > 1){
        if (flag) {
            q.push(q.front());
            q.pop();
            flag = abs(flag - 1);
        }
        else {
            q.pop();
            flag = abs(flag - 1);
        }
    }
    cout << q.front() << '\n';
    return 0;
}