// #include <bits/stdc++.h>
// using namespace std;

// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     stack<int> S;
//     int ans[n];
//     int cnt;
//     int pos = 0;
//     for (int i = 0; i < n; i++){
//         int t;
//         cin >> t;

//         // exception for the first iteration
//         if (i == 0){
//             cnt = t;
//             ans[i] = 0;
//         }

//         // after the second interation
//         else{
//             if (t < S.top()){  // 5 < 9
//                 pos = i;
//                 ans[i] = pos;
//             }
//             else if (t < cnt){  // 7 < 9
//                 ans[i] = pos;
//             }
//             else{ // 9
//                 cnt = t;
//                 ans[i] = 0;
//             }
//         }
//         S.push(t);
//     }

//     int sum = 0;
//     for (int j = 0; j < n; j++){
//         sum += ans[j];
//     }
//     if (sum == 0) cout << 0;
//     else{
//         for (int k = 0; k < n; k++){
//             cout << ans[k] << ' ';
//         }
//     }
//     cout << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (tower.top().X < height)
      tower.pop();    
    cout << tower.top().Y << " ";
    tower.push({height, i});      
  }
}