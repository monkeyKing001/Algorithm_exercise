#include <iostream>
using namespace std;
// 방 번호

int N;
int arr[10];
int ans;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);   
    cin >> N;
    while(N>=1){
        arr[N%10] += 1;
        N /= 10;
        // cout << N << endl;
    }
    // for(auto i : arr) cout << i << " ";

    for (int i = 0; i < 10; i++){
        // cout << arr[i] << " ";
        if(i == 6 || i == 9) ans = max(ans, (arr[6]+arr[9]-1)/2+1);
        else ans = max(ans, arr[i]);
    }
    cout << ans;
}