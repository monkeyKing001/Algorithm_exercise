#include <iostream>
#include <vector>
using namespace std;
// 거짓말

int N, M;
int tnum; // 진실을 아는 사람 수
int parr[51]; // parent array
// int pparr[51][51]; // party n people array 
vector<int> vi[51]; // party n people vec
int know[51];
int ans;

int ppnum;

int find_func(int x){
    if (x == parr[x]) return x;
    return parr[x] = find_func(parr[x]);
}

bool is_union_func(int x, int y){
    int xr = find_func(x);
    int yr = find_func(y);
    
    return x == y;
}

void union_func(int x, int y){
    int xr = find_func(x);
    int yr = find_func(y);

    if (know[xr] && know[yr]) {
        if (xr > yr) parr[yr] = xr;
        else parr[xr] = yr;
    }
    else if (know[xr]) parr[yr] = xr;
    else if (know[yr]) parr[xr] = yr;
    else {
        if (xr > yr) parr[xr] = yr;
        else parr[yr] = xr;
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> tnum;
    for (int i = 0; i < tnum; ++i){
        int a;
        cin >> a;
        know[a] = 1;
    }
    for (int i = 1; i <= N; ++i) parr[i] = i;
    for (int i = 0; i < M; ++i){
        cin >> ppnum;
        int a;
        cin >> a;
        vi[i].push_back(a);
        for (int j = 1; j < ppnum; ++j){
            int b;
            cin >> b;
            vi[i].push_back(b);
            union_func(vi[i][j-1], b);
        }
    }
    for (int i = 0; i < M; ++i){
        bool flag = false;
        for (int j = 0; j < vi[i].size(); ++j){
            // cout << find_func(vi[i][j]) << '\n';
            if (know[find_func(vi[i][j])]) {
                flag = true;
                break;
            }
        }
        if (!flag) ans ++;
    }
    cout << ans;
}