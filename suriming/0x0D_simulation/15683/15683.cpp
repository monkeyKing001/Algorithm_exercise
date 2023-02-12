#include <iostream>
#include <vector>
using namespace std;
//감시

int N, M;
int darr[9][9];
int ans = 64;
int tot = 0;
vector<pair<int, pair<int, int> > > v;

void cnt_back(int r, int c, int dir){
    if (dir == 0){
        for (int i=c+1; i<M; i++){
            if (darr[r][i] < 0) darr[r][i] += 1;
            else if (darr[r][i] == 6) return;
        }
    }   
    else if (dir == 1){
        for (int i=r+1; i<N; i++){
            if (darr[i][c] < 0) darr[i][c] += 1;
            else if (darr[i][c] == 6) return;
        }
    }
    else if (dir == 2){
        for (int i=c-1; i>=0; i--){
            if (darr[r][i] < 0) darr[r][i] += 1;
            else if (darr[r][i] == 6) return;
        }
    }
    else if (dir == 3){
        for (int i=r-1; i>=0; i--){
            if (darr[i][c] < 0) darr[i][c] += 1;
            else if (darr[i][c] == 6) return;
        }
    }
    return;
}

int cnt_availables(int r, int c, int dir){
    int cnt = 0;
    if (dir == 0){
        for (int i=c+1; i<M; i++){
            if (darr[r][i] <= 0) darr[r][i] -= 1;
            // 처음 본 게 -1 이 되어있을 것.
            if (darr[r][i] == -1) { 
                cnt += 1;
            }
            else if (darr[r][i] == 6) return cnt;
        }
    }   
    else if (dir == 1){
        for (int i=r+1; i<N; i++){
            if (darr[i][c] <= 0) darr[i][c] -= 1;
            if (darr[i][c] == -1) {
                cnt += 1;
            }
            else if (darr[i][c] == 6) return cnt;
        }
    }
    else if (dir == 2){
        for (int i=c-1; i>=0; i--){
            if (darr[r][i] <= 0) darr[r][i] -= 1;
            if (darr[r][i] == -1) {
                cnt += 1;
            }
            else if (darr[r][i] == 6) return cnt;
        }
    }
    else if (dir == 3){
        for (int i=r-1; i>=0; i--){
            if (darr[i][c] <= 0) darr[i][c] -= 1;
            if (darr[i][c] == -1) {
                cnt += 1;
            }
            else if (darr[i][c] == 6) return cnt;
        }
    }
    return cnt;
}

void cctv(int cur_idx){
    // 종료 condition
    if (cur_idx == v.size()) {
        // cout << tot << '\n';
        if (tot < ans) ans = tot;
        return;
    }
    
    // cout << "tot:" << tot << '\n';
    // cout << "ans:" << ans << '\n';
    auto cctv_id = v[cur_idx].first;
    auto cur = v[cur_idx].second;
    if (cctv_id == 1){
        // dir 순서 : 동 남 서 북 
        for (int dir=0; dir<4; dir++){
            int cur_av_adds = 0;
            cur_av_adds += cnt_availables(cur.first, cur.second, dir);
            // cout << "cctv1: " << cur_av_adds << '\n';
            tot -= cur_av_adds;
            cctv(cur_idx+1);
            tot += cur_av_adds;
            cnt_back(cur.first, cur.second, dir);
        }
    }
    if (cctv_id == 2){
        for (int dir=0; dir<2; dir++){
            int cur_av_adds = 0;
            cur_av_adds += cnt_availables(cur.first, cur.second, dir);
            cur_av_adds += cnt_availables(cur.first, cur.second, dir+2);
            // cout << cur_av_adds << '\n';
            tot -= cur_av_adds;
            cctv(cur_idx+1);
            tot += cur_av_adds;
            cnt_back(cur.first, cur.second, dir);
            cnt_back(cur.first, cur.second, dir+2);
        }
    }
    if (cctv_id == 3){
        for (int dir=0; dir<4; dir++){
            int cur_av_adds = 0;
            cur_av_adds += cnt_availables(cur.first, cur.second, dir % 4);
            cur_av_adds += cnt_availables(cur.first, cur.second, (dir+1) % 4);
            tot -= cur_av_adds;
            cctv(cur_idx+1);
            tot += cur_av_adds;
            cnt_back(cur.first, cur.second, dir % 4);
            cnt_back(cur.first, cur.second, (dir+1) % 4);
        }
    }
    if (cctv_id == 4){
        for (int dir=0; dir<4; dir++){
            int cur_av_adds = 0;
            cur_av_adds += cnt_availables(cur.first, cur.second, (dir+1) % 4);
            cur_av_adds += cnt_availables(cur.first, cur.second, (dir+2) % 4);
            cur_av_adds += cnt_availables(cur.first, cur.second, (dir+3) % 4);
            tot -= cur_av_adds;
            cctv(cur_idx+1);
            tot += cur_av_adds;
            cnt_back(cur.first, cur.second, (dir+1) % 4);
            cnt_back(cur.first, cur.second, (dir+2) % 4);
            cnt_back(cur.first, cur.second, (dir+3) % 4);
        }
    }
    if (cctv_id == 5){
        int cur_av_adds = 0;
        cur_av_adds += cnt_availables(cur.first, cur.second, 0);
        cur_av_adds += cnt_availables(cur.first, cur.second, 1);
        cur_av_adds += cnt_availables(cur.first, cur.second, 2);
        cur_av_adds += cnt_availables(cur.first, cur.second, 3);
        // cout << "cctv 5: " << cur_av_adds << '\n';
        tot -= cur_av_adds;
        cctv(cur_idx+1);
        tot += cur_av_adds;
        cnt_back(cur.first, cur.second, 0); 
        cnt_back(cur.first, cur.second, 1);
        cnt_back(cur.first, cur.second, 2);
        cnt_back(cur.first, cur.second, 3);
    }
}

int main(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> darr[i][j];
            if (darr[i][j] == 0) tot += 1;
            if (darr[i][j] != 0 && darr[i][j] != 6) v.push_back(make_pair(darr[i][j], make_pair(i, j)));
        }
    }
    cctv(0);
    cout << ans;
    return 0;
}