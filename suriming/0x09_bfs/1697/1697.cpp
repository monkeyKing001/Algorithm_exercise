#include <iostream>
#include <queue>
using namespace std;
//숨바꼭질
int N, K;
queue<int> q;
int dist[100001];

void bfs(){
    while(!dist[K]){
        int cur = q.front(); q.pop();
        int nr[3] = {cur-1, cur+1, 2*cur};
        for (int i=0; i<3; i++){
            int next = nr[i];
            if (next<0 || next>100000) continue;
            if (dist[next] || next == N) continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    q.push(N);
    if (N == K){
        cout << 0;
        return 0;
    }
    bfs();
    cout << dist[K];
    return 0;
}