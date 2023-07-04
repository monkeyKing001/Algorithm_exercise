#include <iostream>
using namespace std;
// N과 M(2)

int N, M;
int arr[9];
bool isUsed[9];

void bt(int x){
    if (x == M){
        for (int i=0; i<M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    // 그 전 숫자보다 큰것만!
    int st = 1;
    if (x != 0) st = arr[x-1] + 1;
    for (int i = st; i <= N; i++){
        if (!isUsed[i]){
            arr[x] = i;
            isUsed[i] = 1;
            bt(x+1);
            isUsed[i] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    bt(0);
}