#include <iostream>
using namespace std;
// 랜선 자르기
// Parametric Search
typedef long long ll;

int K, N;
int arr[10001];

// 길이가 x 일 때 랜선이 N개 이상인가
bool solve(ll x){
    ll cur = 0;
    for (int i=0; i<K; i++) cur += (arr[i]/x);
    return cur >= N;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    for (int i=0; i<K; i++) cin >> arr[i];
    ll st = 1;
    ll en = 0x7fffffff;
    while(st < en){
        //(st+en)/2 가 아님에 주목 
        ll mid = (st+en+1)/2;
        if (solve(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}