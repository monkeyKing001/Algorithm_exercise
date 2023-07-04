#include <iostream>
#include <queue>
#include <tuple>
//벽 부수고 이동하기
using namespace std;

#define F first
#define S second

int N, M;
char board[1002][1002];
int vis[1002][1002][2];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int ans = -1;

void bfs(int x, int y, int z){
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(x, y, z));
    while(!q.empty()){
        int r, c, t;
        tie(r, c, t) = q.front(); q.pop();
        // cout << r << '\n';
        // cout << t << '\n';
        // cout << N << '\n';
        if (r == N && c == M) {
            // cout << '?' << '\n';
            ans = vis[r][c][t];
            return;
        }
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            // cout << vis[nr][nc][t] << '\n';
            // cout << t << '\n';
            // cout << board[nr][nc] << '\n';
            if (nr <= 0 || nc <= 0 || nr > N || nc > M) continue;
            if (board[nr][nc] == '0' && vis[nr][nc][t] == -1) {
                vis[nr][nc][t] = vis[r][c][t]+1;
                q.push(make_tuple(nr, nc, t));
            }
            if (board[nr][nc] == '1' && t == 0){
                // cout << '?' << '\n';
                vis[nr][nc][1] = vis[r][c][t]+1;
                q.push(make_tuple(nr, nc, 1));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i+1][j+1];
            vis[i+1][j+1][0] = vis[i+1][j+1][1] = -1;
        }
    }
    vis[1][1][0] = vis[1][1][1] = 1;
    bfs(1, 1, 0);
    cout << ans;
}