#include<iostream>
#include<queue>
using namespace std;
//그림

#define vt vector
#define ll long long
#define pb push_back
#define pf push_front
#define all(c) (c).begin(), (c).end()
#define rev(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define en '\n'
#define F first
#define S second

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

#define E_ACH2(x, a) for (auto &x : a)
#define E_ACH3(x, y, a) for (auto &[x, y] : a)
#define E_ACH4(x, y, z, a) for (auto &[x, y, z] : a)
#define E_ACHC(...) GET5(__VA_ARGS__, E_ACH4, E_ACH3, E_ACH2)
#define EACH(...) E_ACHC(__VA_ARGS__)(__VA_ARGS__)

const int d4r[4] = {-1,0,1,0}; const int d4c[4] = {0,1,0,-1};

int vis [501][501] = {0, };
int darr [501][501] = {0, };
queue< pair<int, int> > q;
int n, m;

int cnt = 0;
int marea = 0;

void bfs(int x, int y){
    vis[x][y] = 1;
    int area = 0;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int r = q.front().F;
        int c = q.front().S;
        // cout << r << " " << c << endl;

        area += 1;
        q.pop();
        FOR(4){
            int nr = r + d4r[i];
            int nc = c + d4c[i];
            if ((nr>=0) and (nr<n) and (nc>=0) and (nc<m) and (darr[nr][nc]) and (vis[nr][nc] == 0)){
                q.push(make_pair(nr, nc));
                vis[nr][nc] = 1;
                // cout << nr << " " << nc << endl;s
            }
        }
    }
    // cout << area << '\n';
    marea = max(area, marea);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i, n){
        FOR(j, m){      
            int k;
            cin >> k;
            if (k) darr[i][j] = 1;  ;
        }
    }

    FOR(i, n){
        FOR(j, m){
            if ((darr[i][j]) and (!vis[i][j])){
                cnt += 1;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
    cout << marea << '\n';
    return 0;
}