#include <iostream>
using namespace std;

int tot, remain;
int ans;
int money[6] = {500, 100, 50, 10, 5, 1};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> tot;
    remain = 1000-tot;
    for (int i = 0; i < 6; ++i){
        int quo;
        int div = money[i];
        quo = remain/div;
        remain %= div; ans += quo;
    }
    cout << ans;
}