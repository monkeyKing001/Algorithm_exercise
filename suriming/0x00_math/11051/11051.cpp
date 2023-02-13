#include <iostream>
using namespace std;

int N, K;
int darr[1001][1001];
int mod = 10007;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; 
    for (int i=1; i<=N; i++){
        // nC0, nCn = 1
        darr[i][0] = darr[i][i] = 1;
        
        for (int j=1; j<i; j++) darr[i][j] = (darr[i-1][j-1] + darr[i-1][j]) % mod;
    }
    cout << darr[N][K];
}