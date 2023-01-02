#include <bits/stdc++.h>
using namespace std;

int main(void){
    int year;
    cin >> year;

    if (year % 4 == 0){
        if (year % 100 != 0 || year % 400 == 0){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
}