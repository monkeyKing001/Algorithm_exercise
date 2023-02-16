#include <iostream>
#include <algorithm>
using namespace std;
// 숫자 카드 2
// stl upper_bound, lower_bound 사용한 버전

int N, M;
int arr[500001];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    cin >> M;
    while(M--){
        int k;
        cin >> k;
        cout << upper_bound(arr, arr+N, k) - lower_bound(arr, arr+N, k) << ' ';
    }
}