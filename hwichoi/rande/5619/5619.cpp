#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> v;
  cin >> n;
  v.push_back(10001);
  v.push_back(10002);
  v.push_back(10003);
  v.push_back(10004);
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    if (v[0] > input) {
      v.insert(v.begin(), input);
    } else if (v[1] > input) {
      v.insert(v.begin()+1, input);
    } else if (v[2] > input) {
      v.insert(v.begin()+2, input);
    } else if (v[3] > input) {
      v.insert(v.begin()+3, input);
    }
  }

  vector<int> result;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i == j) continue;
      string a = to_string(v[i]);
      string b = to_string(v[j]);
      result.push_back(stoi(a+b));
    }
  }
  sort(result.begin(), result.end());
  cout << result[2];
}
