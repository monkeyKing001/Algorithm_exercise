#include <iostream>
using namespace std;
//N-Queen

int N;
int ans = 0;

bool isChecked1[30];
bool isChecked2[30];
bool isChecked3[30];

void queen(int x){
    if (x == N){
        ans += 1;
        return;
    }
    for (int y=0; y<N; y++){
        if (isChecked1[y] || isChecked2[x+y] || isChecked3[x-y+N-1]) continue;
        isChecked1[y] = 1;
        isChecked2[x+y] = 1;
        isChecked3[x-y+N-1] = 1;
        queen(x+1);
        isChecked1[y] = 0;
        isChecked2[x+y] = 0; 
        isChecked3[x-y+N-1] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    queen(0);
    cout << ans;
    return 0;
}