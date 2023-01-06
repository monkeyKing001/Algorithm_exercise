#include <iostream>
#include <algorithm>
using namespace std;
//1로 만들기

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define ll long long

int dp[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    FOR(i, 4, N+1){
        dp[i] = dp[i-1] + 1;
        if (!(i%3)) dp[i] = min(dp[i], dp[i/3] + 1);
        if (!(i%2)) dp[i] = min(dp[i], dp[i/2] + 1);
    }
    cout << dp[N] << '\n';
    return 0;
}