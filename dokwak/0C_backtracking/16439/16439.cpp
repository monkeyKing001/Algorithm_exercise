#include <algorithm>
#include <bits/stdc++.h>


using namespace std;
int n, m;
int sol = 0;

void bruteForce(vector<vector<int>> &arr, vector<int> bits){
  vector<int> idx;
  for (int i = 0; i < bits.size(); i++) 
    if (bits[i]) idx.push_back(i);
  //calculate
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int temp_sati= 0;
    for (int j = 0; j < idx.size(); j++) 
      temp_sati = max(temp_sati, arr[i][idx[j]]);
    sum += temp_sati;
  }
  sol = max(sol, sum);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int max_bits = (1 << m) - 1;
  vector<int> bits(m, 0);
  for (int i = 0; i < 3; i++) 
    bits[m - i - 1] = 1;
  do{
    bruteForce(arr, bits);
  } while(next_permutation(bits.begin(), bits.end()));
  cout << sol;
  return (0);
}

