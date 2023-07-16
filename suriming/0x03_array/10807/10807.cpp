#include <iostream>
using namespace std;
// 개수 세기
int N;
int arr[201];
int v;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        int t;
        cin >> t;
        arr[t+100] += 1;
    }
    cin >> v;
    cout << arr[v+100];
}