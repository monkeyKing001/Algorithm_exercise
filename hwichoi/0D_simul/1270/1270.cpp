#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int t,n;
long long ti[100001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> t;
		int mid = t/2;
		for (int i = 0; i < t; ++i) {
			cin >> ti[i];
		}
		sort(ti, ti+t);
		int cnt = 0;
		int flag = 0;
		for (int i = 0; i < t; ++i) {
			if (i == 0 || ti[i] != ti[i-1]) {
				if (cnt > mid) {
					flag = 1;
					cout << ti[i-1] << '\n';
					break;
				}
				cnt = 1;
			}
			else
				cnt++;
		}
		if (!flag) {
			if (cnt > mid) cout << ti[t-1] << '\n';
			else cout << "SYJKGW\n";
		}
	}
	return (0);
}

