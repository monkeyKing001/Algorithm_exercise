#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
//불!

#define F first
#define S second

int R, C;
string board[1001];
int fdist[1001][1001];
int jdist[1001][1001];
queue<pair<int, int> > fq;
queue<pair<int, int> > jq;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void fbfs(){
    while(!fq.empty()){
        auto cur = fq.front(); fq.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr<0 || nc<0 || nr>=R || nc>=C) continue;
            if (board[nr][nc] == '#' || board[nr][nc] == 'F' || fdist[nr][nc]) continue;
            fdist[nr][nc] = fdist[cur.F][cur.S] + 1;
            fq.push(make_pair(nr, nc));
        }
    }
}

void jbfs(){
    while(!jq.empty()){
        auto cur = jq.front(); jq.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (nr<0 || nc<0 || nr>=R || nc>=C) {
                cout << jdist[cur.F][cur.S] + 1;
                exit(0);
            }
            if (board[nr][nc] == '#' || board[nr][nc] == 'F' || jdist[nr][nc]) continue;
            if (fdist[nr][nc] && jdist[cur.F][cur.S]+1 >= fdist[nr][nc]) continue;
            jdist[nr][nc] = jdist[cur.F][cur.S] + 1;
            jq.push(make_pair(nr, nc));
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> board[i];
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == 'F') {
                fq.push(make_pair(i, j));
            }
            if (board[i][j] == 'J'){
                jq.push(make_pair(i, j));
            }
        }
    }
    fbfs();
    jbfs();
    cout << "IMPOSSIBLE";
    return 0;
}