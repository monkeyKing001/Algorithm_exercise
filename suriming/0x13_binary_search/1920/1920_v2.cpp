#include <iostream>
#include <algorithm>
using namespace std;
// 수 찾기
// STL binary search 를 이용

int N, M;
int arr[100001];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    // binary search에 넣으려면 범위가 반드시 오름차순 정렬이어야 함. 
    sort(arr, arr+N);
    cin >> M;
    while (M--) {
        int k;
        cin >> k;
        cout << binary_search(arr, arr+N, k) << '\n';
    }
}