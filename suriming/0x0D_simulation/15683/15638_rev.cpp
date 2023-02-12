#include <iostream>
#include <vector>
using namespace std;
//감시 revised
//백트래킹을 사용하지 않은 풀이 그냥 방향도 다보고 어레이도 복사하고 계속 매번 초기함함

int N, M;
int board1[10][10];
int board2[10][10];
vector<pair<int, int> > cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int a, int b){
    return a < 0 || a >=N || b < 0 || b >= M; 
}

void upd(int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y) || board2[x][y] == 6) return;
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int MN = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back(make_pair(i, j));
            if (board1[i][j] == 0) MN++;
        }
    }

    for (int tmp=0; tmp<(1<<(2*cctv.size())); tmp++){
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) board2[i][j] = board1[i][j];
        }
        int brute = tmp;
        for (int i=0; i<cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            if (board1[x][y] == 1){
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2){
                upd(x, y, dir);
                upd(x, y, dir+2);
            }
            else if (board1[x][y] == 3){
                upd(x, y, dir);
                upd(x, y, dir+1);
            }
            else if (board1[x][y] == 4){
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            }
            else{
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            }
        }
        int val = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                val += (board2[i][j] == 0);
        MN = min(MN, val);
    }
    cout << MN;
    return 0;
}