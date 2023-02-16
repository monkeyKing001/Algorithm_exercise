#include <iostream>
#include <queue>
using namespace std;
// 적록색약 

#define F first
#define S second

int N;
char board[101][101];
int vis[101][101];
int vis2[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
int ans, ans2;

void bfs1(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (!vis[nr][nc]) {
                if (board[nr][nc] == board[cur.F][cur.S]) {
                    vis[nr][nc] = 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }
    }
}
void bfs2(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (!vis2[nr][nc]) {
                if (board[nr][nc] == board[cur.F][cur.S] || (board[nr][nc] != 'B' && board[cur.F][cur.S]!= 'B')) {
                    vis2[nr][nc] = 1;
                    q.push(make_pair(nr, nc));
                } 
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            cin >> board[i][j];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!vis[i][j]) {
                bfs1(i, j); 
                ans ++;
            }
            if (!vis2[i][j]) {
                bfs2(i, j); 
                ans2 ++;
            }
        }
    }
    cout << ans << ' ' << ans2;
}