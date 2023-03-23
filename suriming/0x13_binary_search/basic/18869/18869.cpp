#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 멀티버스 2
// 좌표 압축을 했을 때 인덱스가 똑같은 걸 찾자. 
int M, N;
vector<int> v[101];
int arr[101][10001];
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            v[i].push_back(arr[i][j]);
        }
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        for (int j = 0; j < N; j++){
            auto t = lower_bound(v[i].begin(), v[i].end(), arr[i][j]) - v[i].begin();
            arr[i][j] = t;
        }
    }
    for (int i = 0; i < M-1; i++) {
        for (int j = i+1; j < M; j++){
            for (int k = 0; k < N; k++) {
                if (arr[i][k] != arr[j][k]) break;
                if (k == N-1) ans += 1;
            }
        }
    }
    cout << ans;
}   