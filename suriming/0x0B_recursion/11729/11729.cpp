#include <iostream>
using namespace std;
//하노이 탑 이동순서

int N;

void hanoi(int a, int b, int n){
    if (n == 1){
        cout << a << " " << b << '\n';
        return;
    }
    hanoi(a, 6-a-b, n-1);
    cout << a << " " << b << '\n';
    hanoi(6-a-b, b, n-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    hanoi(1, 3, N);
    return 0;
}