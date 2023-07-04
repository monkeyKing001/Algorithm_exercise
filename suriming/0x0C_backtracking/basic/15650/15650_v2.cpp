#include <iostream>
#include <algorithm>
using namespace std;
// N과 M 2

int N, M;
int arr[9];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) arr[i] = i < M ? 0 : 1;
    do{
        for (int i = 0; i < N; i++){
            if (arr[i] == 0) cout << i+1 << ' ';
        }
        cout << '\n';
    } while(next_permutation(arr, arr+N));
    
    return 0;
}