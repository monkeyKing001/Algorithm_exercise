#include <iostream>
#include <string>
#include <queue>
using namespace std;
//미로 탐색

#define F first
#define S second

int N, M;
string board[101];
int dist[101][101];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i=0; i<4; i++){
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (dist[nr][nc] || board[nr][nc] == '0') continue;
            dist[nr][nc] = dist[cur.F][cur.S] + 1;
            q.push(make_pair(nr,nc));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++){
       cin >> board[i];
    }
    bfs(0, 0);
    cout << dist[N-1][M-1] + 1;
    return 0;
}