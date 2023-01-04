#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // content: input
    // m: num of commands
    string content;
    int m;
    
    cin >> content;
    cin >> m;

    // L: linked list
    // set the curusor to the end of the L
    list<char> L;
    for(auto x: content) L.push_back(x);
    auto cursor = L.end();

    // iterate along m
    for(int i = 0; i < m; i++){
        char com;
        cin >> com;

        // split cases
        if(com == 'L'){
            if(cursor != L.begin()) cursor--;
        } 
        else if(com == 'D'){
            if(cursor != L.end()) cursor++;
        } 
        else if(com == 'B'){
            if(cursor != L.begin()){
                cursor--;
                cursor = L.erase(cursor);
            }
        } 
        else{   // 'P'
            char add;
            cin >> add;
            L.insert(cursor, add);
        } 
    }
    for(auto c : L) cout << c;
}