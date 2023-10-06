#include <iostream>
#include <queue>
using namespace std;
// 쉬운 최단거리

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int n, m;
int board[1001][1001];
int ansboard[1001][1001];
pair<int, int> dpii; // destination(2) coord

void Sol(int sr, int sc){
    queue<pair<int, int> > q;
    q.push(make_pair(sr, sc));
    ansboard[sr][sc] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i){
            int nr = cur.first+dr[i];
            int nc = cur.second+dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (board[nr][nc] == 0) continue;
            if (ansboard[nr][nc] != -1) continue;
            ansboard[nr][nc] = ansboard[cur.first][cur.second]+1;
            q.push(make_pair(nr, nc));
        }
    }
}

void InitAnsBoard(){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            ansboard[i][j] = -1;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    InitAnsBoard();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> board[i][j];
            if (board[i][j] == 2) dpii = make_pair(i, j);
            if (board[i][j] == 0) ansboard[i][j] = 0;
        }
    }
    Sol(dpii.first, dpii.second);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << ansboard[i][j] << ' ';
        }
        cout << '\n';
    }
    
}