#include <iostream>
#include <queue>
using namespace std;
//큐

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    queue<int> q;
    while (N--){
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            q.push(x);
        }
        if (s == "front"){
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }
        if (s == "back"){
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
        if (s == "size"){
            cout << q.size() << '\n';
        }
        if (s == "empty"){
            if (q.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        if (s == "pop"){
            if (!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else{
                cout << "-1\n";
            }
        }
    }
    return 0;
}