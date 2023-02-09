#include <iostream>
using namespace std;
//배열 합치기

int N, M;
int A[1000001];
int B[1000001];
int ans[1000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<M; i++) cin >> B[i];
    int a_idx = 0;
    int b_idx = 0;
    for (int i=0; i<N+M; i++){
        if (a_idx == N) ans[i] = B[b_idx++];
        else if (b_idx == M) ans[i] = A[a_idx++];
        else if (A[a_idx] < B[b_idx]) ans[i] = A[a_idx++];
        else ans[i] = B[b_idx++];
    }
    for (int i=0; i<N+M; i++) cout << ans[i] << " ";
    return 0;
}