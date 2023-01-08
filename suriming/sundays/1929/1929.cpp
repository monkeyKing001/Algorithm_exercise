#include <iostream>
using namespace std;
//소수 구하기

int M, N;
int iarr[1000001];

void eratos(){
    for (int i=2; i*i < N+1; i++){
        if (iarr[i]){
            for (int j=i*i; j<N+1; j+=i){
                iarr[j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    fill_n(iarr+2, N+1, 1);
    eratos();
    for (int i=M; i<N+1; i++){
        if (iarr[i]){
            cout << i << "\n";
        }
    }
    return 0;
}