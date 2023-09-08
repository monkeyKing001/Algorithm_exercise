#include <iostream>
#include <list>
using namespace std;
// 요세푸스 문제

int N, K;
list<int> il;
list<int>::iterator cursor;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) il.push_back(i);
    cursor = il.begin();
    cout << "<";
    while(N--){
        for (int i = 0; i < K-1; ++i){
            cursor ++;
            if (cursor == il.end()) cursor = il.begin();
        }
        cout << *cursor;
        if (N) cout << ", ";
        cursor = il.erase(cursor);
        if (cursor == il.end()) cursor = il.begin();
    }
    cout << ">";
    return 0;
}   