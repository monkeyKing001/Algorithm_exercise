#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
// 미친 아두이노

const int INF = 0x3f3f3f3f;

int R, C;
int iboard[101][101][2]; // 첫번째인덱스: 맵 - .:0, R:1, I:2  2번째인덱스: 아두이노 개수
string js; // 종수가 움직이려고 하는 방향 

int dr[10] = {100, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[10] = {100, -1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<pair<int, int> > clocs_vpii;
pair<int, int> jloc_pi;

queue<pair<int, int> > qpii; // 폭발 예정인 칸들
queue<pair<int, int> > qpii2; // 후보군들만 체크하게 하기 위한 큐


pair<int, int> amove(pair<int, int> aloc, pair<int, int> jloc){
    int ar = aloc.first;
    int ac = aloc.second;
    int jr = jloc.first;
    int jc = jloc.second;
    int mindist = INF;
    int mindir = 0;
    for (int i = 1; i <= 9; ++i){
        int nr = ar+dr[i];
        int nc = ac+dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        int d = abs(nr-jr)+abs(nc-jc);
        if (d < mindist){
            mindist = d;
            mindir = i;
        }
    }
    return make_pair(ar+dr[mindir], ac+dc[mindir]);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; ++i){
        string s;
        cin >> s;
        for (int j = 0; j < C; ++j){
            if (s[j] == '.') {
                iboard[i][j][0] = 0;
                iboard[i][j][1] = 0;
            }
            else if (s[j] == 'R'){
                iboard[i][j][0] = 1;
                iboard[i][j][1] = 1;
                clocs_vpii.push_back(make_pair(i, j));
            }
            else if (s[j] == 'I'){
                iboard[i][j][0] = 2;
                iboard[i][j][1] = 0;
                jloc_pi = make_pair(i, j);
            }
        }
    }
    cin >> js;
    for (int i = 0; i < js.size(); ++i){
        // 1. 종수가 종수아두이노를 이동시키거나 놔둠
        int jdir = js[i]-'0';
        int jnr = jloc_pi.first+dr[jdir];
        int jnc = jloc_pi.second+dc[jdir];
        // cout << "jdir: " << jdir << '\n';
        // 2. 게임 끝나는지 판별

        if (iboard[jnr][jnc][0] == 1){
            cout << "kraj " << i+1;
            return 0;
        }
        else{
            iboard[jloc_pi.first][jloc_pi.second][0] = 0;
            iboard[jnr][jnc][0] = 2;
            jloc_pi = make_pair(jnr, jnc);
        }
        
        // 3. 4. 5
        int csz = clocs_vpii.size();
        // cout << "csz: " << csz << '\n';
        for (int j = 0; j < csz; ++j){
            pair<int, int> aloc = clocs_vpii[j];
            pair<int, int> naloc = amove(aloc, jloc_pi);
            // cout << "aloc: " << aloc.first << ' ' << aloc.second << '\n'; 
            // cout << "naloc: " << naloc.first << ' ' << naloc.second << '\n';


            // 3. 종수가 있는 칸으로 이동한 경우
            if (naloc == jloc_pi){
                cout << "kraj " << i+1;
                return 0;
            }

            // 그외엔 일단 다 움직임
            qpii2.push(naloc);
            iboard[aloc.first][aloc.second][1] = iboard[aloc.first][aloc.second][1]-1;
            iboard[naloc.first][naloc.second][1] = iboard[naloc.first][naloc.second][1]+1;
            clocs_vpii[j] = naloc;
            iboard[aloc.first][aloc.second][0] = 0;
            // iboard[naloc.first][naloc.second][0] = 1;

        }
        // 아두이노 갯수들 확인
        // for (int p = 0; p < R; ++p){
        //     for (int q = 0; q < C; ++q) cout << iboard[p][q][1];
        //     cout << '\n';
        // }
        // cout << '\n';

        // 2개이상있는 칸 골라내서 qpii에 넣음
        
        while (!qpii2.empty()){
            pair<int, int> aloc = qpii2.front(); qpii2.pop();
            if (iboard[aloc.first][aloc.second][1] > 1){
                // qpii.push(aloc);
                iboard[aloc.first][aloc.second][0] = 0;
                iboard[aloc.first][aloc.second][1] = 0;
                for (int j = 0; j < csz; ++j){
                    if (clocs_vpii[j] == aloc){
                        clocs_vpii[j] = make_pair(-1, -1);
                    }
                }
            }
            else if (iboard[aloc.first][aloc.second][1] == 1){
                iboard[aloc.first][aloc.second][0] = 1;
            }
        }
        // 칸 폭발시켜 아두이노 없애기
        // while(!qpii.empty()){
        //     pair<int, int> aloc = qpii.front(); qpii.pop();
        //     iboard[aloc.first][aloc.second][0] = 0;
        //     iboard[aloc.first][aloc.second][1] = 0;
        //     for (int j = 0; j < csz; ++j){
        //         if (clocs_vpii[j] == aloc){
        //             clocs_vpii[j] = make_pair(-1, -1);
        //         }
        //     }
        // }
        vector<pair<int, int> > tmp_vpii;
        for (int j = 0; j < csz; ++j){
            if (clocs_vpii[j].first != -1) tmp_vpii.push_back(clocs_vpii[j]);
        }
        clocs_vpii = tmp_vpii;

        // for (int p = 0; p < R; ++p){
        //     for (int q = 0; q < C; ++q) cout << iboard[p][q][0];
        //     cout << '\n';
        // }

        // cout << '\n';
    }
    // 답
    for (int i = 0; i < R; ++i){
        // for (int j = 0; j < C; ++j) cout << board[i][j];
        for (int j = 0; j < C; ++j){
            if (iboard[i][j][0] == 0) cout << '.';
            else if (iboard[i][j][0] == 1) cout << 'R';
            else if (iboard[i][j][0] == 2) cout << 'I';
            else if (iboard[i][j][0] == 3) cout << 'B';
        }
        cout << '\n';
    }
}