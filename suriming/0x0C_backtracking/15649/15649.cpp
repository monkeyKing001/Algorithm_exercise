#include <iostream>
using namespace std;
//N과 M

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
    for (int i=1; i<=N; i++){
        if (!isUsed[i]){
            arr[x] = i;
            isUsed[i] = 1;
            bt(x+1);
            isUsed[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    bt(0);
    return 0;
}