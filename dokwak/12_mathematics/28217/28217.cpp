#include <bits/stdc++.h>

using namespace std;
int n, m;


void printTwoDVec(vector<vector<bool>> vec){
  cout << "two Dimension vector print\n";
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << vec[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<bool>> A(n, vector<bool>(n, false));
  vector<vector<bool>> A2(n, vector<bool>(n, false));
  vector<vector<bool>> A3(n, vector<bool>(n, false));
  vector<vector<bool>> Ar(n, vector<bool>(n, false));
  vector<vector<bool>> A2r(n, vector<bool>(n, false));
  vector<vector<bool>> A3r(n, vector<bool>(n, false));
  vector<vector<bool>> B(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      short num = 0;
      cin >> num;
      A[i][j] = num == 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      short num = 0;
      cin >> num;
      B[i][j] = num == 1;
    }
  }
  //rotate A2
  for (int i = 0; i < n; i++) {
    int a2_c = n - 1 - i;
    int a2_r_start = a2_c;
    for (int j = 0; j <= i; j++) {
      int a2_r = a2_r_start + j;
      A2[a2_r][a2_c] = A[i][j];
    }
  }
  
  //rotate A3
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      A3[n - 1 - j][i - j] = A[i][j];
    }
  }
  //reflect A4
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      Ar[i][i - j] = A[i][j];
      A2r[i][i - j] = A2[i][j];
      A3r[i][i - j] = A3[i][j];
    }
  }
//  printTwoDVec(A);
//  printTwoDVec(A2);
//  printTwoDVec(A3);
//  printTwoDVec(Ar);
//  printTwoDVec(A2r);
//  printTwoDVec(A3r);
  
  int A1_score = 0, A2_score = 0, A3_score = 0, A1r_score = 0, A2r_score = 0, A3r_score = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (A[i][j] != B[i][j]) A1_score++;
      if (A2[i][j] != B[i][j]) A2_score++;
      if (A3[i][j] != B[i][j]) A3_score++;
      if (Ar[i][j] != B[i][j]) A1r_score++;
      if (A2r[i][j] != B[i][j]) A2r_score++;
      if (A3r[i][j] != B[i][j]) A3r_score++;
    }
  }
  int ans = INT_MAX;
  ans = min(ans, A1_score);
  ans = min(ans, A2_score);
  ans = min(ans, A3_score);
  ans = min(ans, A1r_score);
  ans = min(ans, A2r_score);
  ans = min(ans, A3r_score);
  cout << ans;
  return (0);
}

