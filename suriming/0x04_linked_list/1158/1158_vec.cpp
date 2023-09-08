#include <iostream>
#include <vector>
using namespace std;
// 요세푸스 문제

int N, K;
int pre[5001], nxt[5001];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i){
        pre[i] = i-1;
        nxt[i] = i+1;
    }
    pre[1] = N; nxt[N] = 1;
    cout << "<";
    int cursor = 1;
    while (N--){
        for (int j = 0; j < K-1; ++j){
            cursor = nxt[cursor];
        }
        cout << cursor;
        if (N) cout << ", ";
        nxt[pre[cursor]] = nxt[cursor];
        pre[nxt[cursor]] = pre[cursor];
        cursor = nxt[cursor];
    }
    cout << ">";
    return 0;
}   