#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int arr[100002];
stack<int> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  st.push(0);
  vector<char> v;
  int tmp = 1;
  for (int i = 0; i < n; ++i) {
    while (arr[i] > st.top()) {
      st.push(tmp++);
      v.push_back('+');
    }
    if (arr[i] < st.top()) {
      cout << "NO";
      return 0;
    }
    st.pop();
    v.push_back('-');
  }
  for (char c : v) {
    cout << c << '\n';
  }
}
