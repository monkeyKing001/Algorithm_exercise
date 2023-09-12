#include <iostream>
#include <vector>
using namespace std;
// 사회망 서비스(SNS)

const int INF = 0x3f3f3f3f;

int N;
int dp[1000001][2]; // min 얼리어답터 수 - 0: 본인이얼리어답터 x 일때, 1: 얼리어답터일때
vector<int> tr[1000001];
int vis[1000001];

void dfs(int x){
    vis[x] = 1;    
    for(int i = 0; i < tr[x].size(); ++i){
        int c = tr[x][i];
        if (vis[c]) continue;
        dfs(c);
        dp[x][0] += dp[c][1]; // 자식이 무조건 얼리어답터
        dp[x][1] += min(dp[c][0], dp[c][1]); // 자식이 얼리어답터일수도 아닐수도 있기떄문에
    }
    dp[x][1]++;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}