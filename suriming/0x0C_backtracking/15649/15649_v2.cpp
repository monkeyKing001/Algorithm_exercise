#include <iostream>
using namespace std;
//N과 M (1)

int N, M;
int arr[9];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for (int i=0; i<N; i++){
        arr[i] = i+1;
    }

    do{
        // flag = false
        for (int j=0; j<M; j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
    } while(next_permutation(arr, arr+N));
    
    return 0;
}