#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long total;
int arr[505050];
long long ldp[505050], ldp2[505050], rdp[505050];

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
    total += arr[i];
	}

  // ldp[k]: k를 끝으로 하는 부분수열 중 최대 총합
  // rdp[k]: k를 시작으로 하는 부분수열 중 최대 총합
  ldp[0] = -2000000000;
	for (int i = 1; i <= n; ++i) {
    ldp[i] = max(0LL, ldp[i-1]) + arr[i];
    ldp2[i] = max(ldp2[i-1], ldp[i]);
	}

  rdp[n+1] = -2000000000;
  for (int i = n; i > 0; --i) {
    rdp[i] = max(0LL, rdp[i+1]) + arr[i];
  }

  long long res = 0;
  for (int i = 1; i < n; ++i) {
    res = max(ldp2[i] + rdp[i+1], res);
  }

  cout << res + total;
}
