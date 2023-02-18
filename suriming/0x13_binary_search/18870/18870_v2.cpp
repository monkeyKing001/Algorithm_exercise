#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 좌표 압축 
// stl unique, erase 이용 

int N;
int arr[1000001];
vector<int> v;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    // unique는 중복 제거된 원소 뒤에 쓰레기 값이 시작되는 구간을 return
    // erase를 이용해서 바로 이거랑 end 로 뒤쪽을 날리면 됨
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<N; i++){
        cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << ' ';
    }
}