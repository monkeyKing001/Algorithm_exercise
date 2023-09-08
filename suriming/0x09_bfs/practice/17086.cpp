#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// 아기 상어 2

int N, M;
int board[51][51];
int sfdist[51][51][2]; // 안전거리 기록용, 0번째 max값, 1번째 cur값
int vis[51][51]; // 각 상어마다 초기화시키는 방문
vector<pair<int, int> > sv; // 상어들 좌표

int ans = 0;

int dr[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dc[8] = { 1, 1, 0, -1, -1, -1, 0, 1};

void bfs(int r, int c){
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    sfdist[r][c][1] = 0; sfdist[r][c][0] = 0; 
    vis[r][c] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int r = cur.first, c = cur.second;
        for (int i = 0; i < 8; ++i){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (!vis[nr][nc]) {
                sfdist[nr][nc][1] = sfdist[r][c][0]+1;
                if (sfdist[nr][nc][0] != -1 && sfdist[nr][nc][1] < sfdist[nr][nc][0]) sfdist[nr][nc][0] = sfdist[nr][nc][1];
                if (sfdist[nr][nc][0] == -1 ) sfdist[nr][nc][0] = sfdist[nr][nc][1];
                vis[nr][nc] = 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

void clearvis(){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            vis[i][j] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> board[i][j];
            if (board[i][j]) sv.push_back(make_pair(i, j));
            sfdist[i][j][0] = -1;
        }
    }
    for (int i = 0; i < sv.size(); ++i){
        clearvis();
        bfs(sv[i].first, sv[i].second);
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            ans = max(sfdist[i][j][0], ans);
        }
    }
    cout << ans;
}