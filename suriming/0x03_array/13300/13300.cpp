#include <iostream>
using namespace std;
// 방 배정

int N, K;
int arr[7][2];
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        int S, Y;
        cin >> S >> Y;
        arr[Y][S] += 1;
    }
    for (int i = 1; i <= 6; i++){
        for (int j = 0; j < 2; j++){
            ans += (arr[i][j]+K-1)/K;
        }
    }
    cout << ans;
}