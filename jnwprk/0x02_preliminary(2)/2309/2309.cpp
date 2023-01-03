#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int heights[9];
    for (int i = 0; i < 9; i++) cin >> heights[i];

    int sum;
    sum = 0;

    for (int h : heights) sum += h; 
    int resi;
    resi = sum - 100;

    int res[2];
    for (int i = 0; i < 8; i++){
        for (int j = i + 1; j < 9; j++){
            if (heights[i] + heights[j] == resi){
                res[0] = heights[i];
                res[1] = heights[j];
            }
        }
    }

    int result[7];
    int j;
    j = 0;
    for (int h : heights){
        if (h != res[0] && h != res[1]){
            result[j] = h;
            j++;
        }
    }
    sort(result, result + 7);
    for(int r :result) cout << r << '\n';
}  