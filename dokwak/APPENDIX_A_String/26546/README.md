# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
no comment

# Approach
<!-- Describe your approach to solving the problem. -->
no comment

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Code
```cpp []
#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
    string buf;
    string output;
    int start, end;
    cin >> buf >> start >> end;
    output.reserve(buf.size());
    for (int i = 0; i < buf.size(); i++) 
      if (i < start || i >= end) output.push_back(buf[i]);
    cout << output << "\n";
	}
	return (0);
}

```
