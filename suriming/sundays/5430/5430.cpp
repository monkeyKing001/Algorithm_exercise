#include <iostream>
#include <string>
#include <deque>
using namespace std;
//AC

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int isRev = 0;
        int isErr = 0;
        deque<string> dq;
        string cmd;
        int n;
        cin >> cmd;
        cin >> n;
        string arrs;
        cin >> arrs;
        string s;
        s.clear();
        int cnt = 1;
        while(n){
            if ((arrs[cnt] != ',') and (arrs[cnt] != ']')) s += arrs[cnt];
            else {
                dq.push_back(s);
                s.clear();
                n -= 1;
            }
            cnt += 1;
        }
        // for(int i=1; i<arrs.size(); i++){
        //     // cout << arrs[i] << " ";
        //     if ((arrs[i] != ',') and (arrs[i] != ']')) s += arrs[i];
        //     else {
        //         dq.push_back(s);
        //         s.clear();
        //     }
        // }
        for (int i=0; i<cmd.size(); i++){
            if (isErr) break;
            if (cmd[i] == 'R'){
                isRev = abs(isRev - 1);
            }
            if (cmd[i] == 'D'){
                if (dq.empty()){
                    isErr = 1;
                    break;
                }
                else{
                    if (isRev) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if (isErr){
            cout << "error\n";
            continue;
        }
        cout << '[';
        if (isRev){
            while(dq.size()){
                cout << dq.back();
                if (dq.size() != 1) cout << ',';
                dq.pop_back();
            }
        }
        else{
            while(dq.size()){
                cout << dq.front();
                if (dq.size() != 1) cout << ',';
                dq.pop_front();
            }
        }
        cout << ']' << '\n';
    }
    return 0;
}