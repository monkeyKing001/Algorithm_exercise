#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<ll> distances(n - 1); 
  vector<ll> distancesPrefixSum(n, 0); 
  for (int i = 0; i < n - 1; i++) cin >> distances[i];
  partial_sum(distances.begin(), distances.end(), distancesPrefixSum.begin() + 1);
  vector<ll> cost(n); 
  vector<int> rightSmalerIndex(n, -1); 
  for (int i = 0; i < n; i++) cin >> cost[i];
  stack<int> s;
  for (int i = n - 1; i >= 0; i--){
    int cur_num = cost[i];
    while (s.size() && cost[s.top()] > cur_num) s.pop();
    if (s.size() == 0) rightSmalerIndex[i] = -1;
    else rightSmalerIndex[i] = s.top();
    s.push(i);
  }
  ll totalCost = 0;
  int cur_idx = 0;
  while (cur_idx < n - 1) {
    //fuel here for the most right;
    if (rightSmalerIndex[cur_idx] == -1){
      totalCost += 
        (cost[cur_idx] * (distancesPrefixSum.back() - distancesPrefixSum[cur_idx]));
      break;
    }
    //fuel here for the most left right RightSmaller;
    else {
      int next_idx = rightSmalerIndex[cur_idx];
      ll distance = distancesPrefixSum[next_idx] - distancesPrefixSum[cur_idx];
      ll cur_cost = cost[cur_idx];
      ll to_cost = cost[cur_idx] * distance;
      totalCost += to_cost;
      cout
        << cur_idx
        << " to "
        << next_idx
        << " with distance and cost : "
        << distance
        << ", "
        << to_cost
        << "\n";
      cur_idx = next_idx;
    }
  }
  cout << totalCost;
  return (0);
}

