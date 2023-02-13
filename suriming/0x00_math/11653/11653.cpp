#include <iostream>
using namespace std;
//소인수분해

int N;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=2; i*i<=N; i++){
        // 한 소수로 여러번 나누어지는 것을 이렇게 
        while(N % i == 0){
             cout << i << '\n';
             N /= i;
        }
    }
    // 마지막 남은 수는 합성수일수가 없음.
    if (N != 1) cout << N;
}