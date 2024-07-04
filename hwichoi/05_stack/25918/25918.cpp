#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> s;

  stack<int> st;
  int maxi = 0;
  for (char c : s) {
    if (c == '(') {
      if (st.empty() || st.top() == '(') st.push(c);
      else if (st.top() == ')') st.pop();
    }
    if (c == ')') {
      if (st.empty() || st.top() == ')') st.push(c);
      else if (st.top() == '(') st.pop();
    }
    int depth = st.size();
    maxi = max(maxi, depth);
  }

  if (!st.empty()) cout << -1;
  else cout << maxi;
}
