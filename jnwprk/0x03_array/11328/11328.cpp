#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--){
        string x, y;
        cin >> x >> y;

        int freq_x[26] = {0};
        int freq_y[26] = {0};

        for (auto c_x: x){
            freq_x[c_x-'a']++;
        }
        for (auto c_y: y){
            freq_y[c_y-'a']++;
        }
        
        int check = 0;
        for (int j = 0; j < 26; j++){
            check += abs(freq_x[j] - freq_y[j]);
        }
        if (check == 0){
            cout << "Possible" << '\n';
        }
        else{
            cout << "Impossible" << '\n';
        }
    }
}