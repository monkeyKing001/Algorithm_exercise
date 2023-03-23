#include <iostream>
// 과자 나눠주기

using namespace std;
int M, N;
int arr[1000001];

// 길이가 x 일 때 과자가 N개 이상인가 
bool solve(int x){
    int cur = 0;
    for (int i = 0; i < N; i++) cur += (arr[i]/x);
    return cur >= M;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int st = 0;
    int en = 0x3f3f3f3f;
    while (st < en){
        int mid = (st+en+1)/2;
        if (solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}