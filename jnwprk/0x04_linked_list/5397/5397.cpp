#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string password;
        cin >> password;

        list<char> res;
        auto cursor = res.begin();
        for (auto pass: password){
            if(pass == '<'){
                if(cursor != res.begin()) cursor--;
            }
            else if(pass == '>'){
                if(cursor != res.end()) cursor++;
            }
            else if(pass == '-'){
                if(cursor != res.begin()){
                    cursor--;
                    cursor = res.erase(cursor);
                }
            }
            else res.insert(cursor, pass);
        }
        for (auto c: res) cout << c;
        cout << '\n';
    }
}