#include <iostream>
#include <queue>
using namespace std;
// 파이프 옮기기 1

int N;
int board[20][20];
int ans = 0; // 방법의 갯수

// 가로로 움직이기, 끝 기준
int wdr = 0;
int wdc = 1;
// 세로
int ldr = 1;
int ldc = 0;
// 대각선
int ddr[3] = {0, 1, 1};
int ddc[3] = {1, 1, 0};

queue<pair<pair<int, int>, int> > q; // <<좌표>, 현재가로세로대각012>

void moveW(int r, int c){
    bool isMoveAvail = true;
    int nr = r+wdr;
    int nc = c+wdc;
    if (nr < 1 || nc < 1 || nr > N || nc > N) isMoveAvail = false;
    if (board[nr][nc] == 1) isMoveAvail = false;
    if (isMoveAvail) q.push(make_pair(make_pair(r+wdr, c+wdc), 0));
}

void moveL(int r, int c){
    bool isMoveAvail = true;
    int nr = r+ldr;
    int nc = c+ldc;
    if (nr < 1 || nc < 1 || nr > N || nc > N) isMoveAvail = false;
    if (board[nr][nc] == 1) isMoveAvail = false;
    if (isMoveAvail) q.push(make_pair(make_pair(r+ldr, c+ldc), 1));
}

void moveD(int r, int c){
    bool isMoveAvail = true;
    for (int i = 0; i < 3; ++i){
        int nr = r+ddr[i];
        int nc = c+ddc[i];
        if (nr < 1 || nc < 1 || nr > N || nc > N) {
            isMoveAvail = false;
            break;
        }
        if (board[nr][nc] == 1) {
            isMoveAvail = false;
            break;
        }
    }
    if (isMoveAvail) {
        q.push(make_pair(make_pair(r+ddr[1], c+ddc[1]), 2));
    }
}

void sol(int r, int c){
    q.push(make_pair(make_pair(r, c), 0));
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cr = cur.first.first, cc = cur.first.second;
        if (cr == N && cc == N) {
            ans++;
            continue;
        }
        int cstatus = cur.second;
        // cout << "cr: " << cr << " cc: " << cc << " stat: " << cstatus << '\n';
        bool isMoveAvail;
        if (cstatus == 0){
            moveW(cr, cc);
            moveD(cr, cc);
        }
        else if (cstatus == 1){
            moveL(cr, cc);
            moveD(cr, cc);
        }
        else if (cstatus == 2){
            moveW(cr, cc);
            moveL(cr, cc);
            moveD(cr, cc);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> board[i][j];
        }
    }
    sol(1, 2);
    cout << ans;
}