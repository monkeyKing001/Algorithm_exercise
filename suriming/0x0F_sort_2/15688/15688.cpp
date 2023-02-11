#include <iostream>
using namespace std;

int N;
int arr[2000001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        arr[tmp+1000000] += 1;
    }
    for (int i=0; i<=2000000; i++){
        while(arr[i]--){
            cout << i-1000000 << '\n';
        }
    }
    return 0;
}