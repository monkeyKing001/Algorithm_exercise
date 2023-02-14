#include <iostream>
#include <algorithm>
using namespace std;
// 숫자 카드 2

int N, M;
int arr[500001];

// target 보다 큰 수가 최초로 나온 인덱스 찾기  
int upper_idx(int target){
    int st = 0;
    // N - 1 이 아님에 주목. 
    // 왜냐면 target 이 들어갈 수 있는 (들어가서도 오름차순이 유지되는)인덱스를 찾는 것이기 때문임.
    int en = N;
    while (st < en){
        int mid = (st + en) / 2;
        // 여기선 같을 때 앞을 줄이게 됨.
        if (arr[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

// target 이 처음 시작하는 인덱스
int lower_idx(int target){
    int st = 0;
    int en = N;
    while (st < en){
        int mid = (st + en) / 2;
        // 같을 때 뒤를 줄여주면 된다.
        if (arr[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
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
        cout << upper_idx(k) - lower_idx(k) << ' ';
    }
}