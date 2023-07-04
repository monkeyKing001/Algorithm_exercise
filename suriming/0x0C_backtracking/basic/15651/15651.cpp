#include <iostream>
using namespace std;
// N과 M (3)

int N, M;
int arr[9];

void bt(int x){
    if (x == M){
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++){
        arr[x] = i;
        bt(x+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    bt(0);
}