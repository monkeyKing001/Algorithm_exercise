#include <iostream>
using namespace std;
//이항 계수 1 

int N, K;
int ans = 1;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i=1; i<=N; i++) ans *= i;
    for (int i=1; i<=K; i++) ans /= i;
    for (int i=1; i<=N-K; i++) ans /= i;
    cout << ans;
}