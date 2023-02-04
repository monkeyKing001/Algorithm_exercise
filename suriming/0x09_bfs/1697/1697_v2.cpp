#include <iostream>
#include <queue>
using namespace std;
//숨바꼭질
int N, K;
queue<int> q;
int dist[100001];

void bfs(){
    while(dist[K] == -1){
        int cur = q.front(); q.pop();
        int nr[3] = {cur-1, cur+1, 2*cur};
        for (int i=0; i<3; i++){
            int next = nr[i];
            if (next<0 || next>100000) continue;
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    fill(dist, dist+100001, -1); //???????
    dist[N] = 0;
    // 위 처럼 해야 처음방문하는 곳과 시작점의 차이를 따로 체킹해주지 않아도 분리해버릴 수 있다. 
    q.push(N);
    bfs();
    cout << dist[K];
    return 0;
}