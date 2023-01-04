#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int rooms[7][2] = {};

    for (int i = 0; i < N; i++){
        int S, Y;
        cin >> S >> Y;
        rooms[Y][S]++;
    }

    int result = 0;
    for (int i = 1; i < 7; i++){
        for (int j = 0; j < 2; j++){
            result += rooms[i][j] / K;
            if (rooms[i][j] % K) result++;
        }
    }
    cout << result;
}
