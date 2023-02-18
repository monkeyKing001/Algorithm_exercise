#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 좌표 압축 

int N;
int arr[1000001];
vector<int> v, res;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<N; i++){
        if (i == 0 || v[i-1] != v[i]) res.push_back(v[i]);
    }
    for (int i=0; i<N; i++) cout << lower_bound(res.begin(), res.end(), arr[i]) - res.begin() << ' ';
}