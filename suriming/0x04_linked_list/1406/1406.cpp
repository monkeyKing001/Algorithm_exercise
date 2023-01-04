#include<iostream>
#include<list>
#include<string>
using namespace std;

#define E_ACH2(x, a) for (auto &x : a)

list<char> cl;
list<char>::iterator cursor;
int M;

void func_P(char x){
    cl.insert(cursor, x);
}

void func_L(){
    if (cursor != cl.begin()) { 
        cursor --;
    }
}

void func_D(){
    if (cursor != cl.end()){
        cursor ++;
    }
}

void func_B(){
    if (cursor != cl.begin()){
        cursor --;
        cursor = cl.erase(cursor);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char c[100001];
    string s;
    cin >> s;
    cin >> M;
    E_ACH2(i, s) cl.push_back(i);
    cursor = cl.end();
    
    // \cout << cursor;

    while (M--){
        char order;
        cin >> order;
        if (order == 'P'){
            char dol;
            cin >> dol;
            func_P(dol);
        }
        else if (order == 'L'){
            func_L();
        }
        else if (order == 'D'){
            func_D();
        }
        else {
            func_B();
        }
    }

    E_ACH2(i, cl) cout << i;

    return 0;
}