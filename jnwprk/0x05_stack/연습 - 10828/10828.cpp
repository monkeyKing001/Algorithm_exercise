#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // # of commands
    int n;
    cin >> n;

    // stack
    stack<int> s;

    while(n--){
        string com;
        cin >> com;

        if(com == "push"){
            int x;
            cin >> x;

            s.push(x);
        }
        else if(com == "pop"){
            if(s.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << s.top() << '\n';
                s.pop();
            }
            
        }
        else if(com == "size"){
            cout << s.size() << '\n';
        }
        else if(com == "empty"){
            if(s.empty()){
                cout << 1 << '\n';
            }  
            else {
                cout << 0 << '\n';
            }
        }
        else if(com == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
}