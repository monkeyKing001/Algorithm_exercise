#include <iostream>
using namespace std;
// 구간 합 구하기 5

int N, M;
int board[1025][1025];
int dp[1025][1025];

int solve(int x1, int y1, int x2, int y2){
    return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}

void cumsum(){
    for (int i = 1; i <= N; ++i) {
        dp[1][i] = board[1][i]+dp[1][i-1];
        dp[i][1] = board[i][1]+dp[i-1][1];
    }
    for (int i = 2; i <= N; ++i){
        for (int j = 2; j <= N; ++j){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+board[i][j];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j){
            int p;
            cin >> p;
            board[i][j] = p;
        }
    }
    cumsum();
    // for (int i = 1; i <= N; ++i){
    //     for (int j = 1; j <= N; ++j){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < M; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2>> y2;
        cout << solve(x1, y1, x2, y2) << '\n';
    }
}