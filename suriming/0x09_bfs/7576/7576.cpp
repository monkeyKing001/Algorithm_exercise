#include <iostream>
#include <queue>
using namespace std;
//토마토
#define F first
#define S second

int M, N;
int board[1001][1001];
int day[1001][1001];
int ans = -1;
queue<pair<int, int> > q;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};


void bfs(){
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i=0; i<4; i++){
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if ((day[nr][nc]) || (board[nr][nc] == -1) || (board[nr][nc] == 1)) continue;
            day[nr][nc] = day[cur.F][cur.S] + 1;
            q.push(make_pair(nr, nc));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 1) q.push(make_pair(i,j));
        }
    }
    bfs();
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if ((board[i][j] == 0) && (day[i][j] == 0)) {
                cout << -1;
                return 0;
            }
            ans = max(ans, day[i][j]);
        }
    }
    cout << ans;
    return 0;
}