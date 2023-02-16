#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//세 수의 합

int N;
int arr[1001];
vector<int> v;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    // 이거 정렬하면 a[i] - a[j]를 큰거부터 뽑기 용이 
    sort(arr, arr+N);
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            v.push_back(arr[i] + arr[j]);
        }
    }
    sort(v.begin(), v.end());
    for (int i=N-1; i>0; i--){
        for (int j=0; j<i; j++) {
            if (binary_search(v.begin(), v.end(), arr[i] - arr[j])){
                cout << arr[i];
                return 0;
            }
        }
    }
}