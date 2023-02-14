#include <iostream>
#include <algorithm>
using namespace std;
//수 찾기

int N, M;
int arr[100001];

int binary_search(int target){
    int st = 0;
    int en = N-1;
    while (st <= en){
        int mid = (st+en)/2;
        if (arr[mid] < target) st = mid+1;
        else if (arr[mid] > target) en = mid - 1;
        else return 1;
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    cin >> M;
    while(M--){
        int k;
        cin >> k;
        cout << binary_search(k) << '\n';
    }
    return 0;
}