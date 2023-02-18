#include <iostream>
#include <algorithm>
using namespace std;
// 숫자 카드

int N, M;
int arr[500001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> M;
    sort(arr, arr + N);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        cout << binary_search(arr, arr+N, k) << ' ';
    }
}   