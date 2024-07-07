#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr1[2000004], arr2[1000002], arr3[1000002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr1[i];
  for (int i = 0; i < n; ++i) {
    cin >> arr2[i];
    arr3[i] = arr2[i];
  }

  reverse(arr3, arr3+n);
  int st1, st2;
  for (int i = 0; i < n; ++i) {
    arr1[i+n] = arr1[i];
    if (arr1[i] == arr2[0]) st1 = i;
    if (arr1[i] == arr3[0]) st2 = i;
  }
  bool flag1 = 1;
  bool flag2 = 1;
  for (int i = 0; i < n; ++i) {
    if (arr1[st1+i] != arr2[i]) flag1 = 0;
    if (arr1[st2+i] != arr3[i]) flag2 = 0;
  }

  if (flag1 || flag2) cout << "good puzzle";
  else cout << "bad puzzle";
}
