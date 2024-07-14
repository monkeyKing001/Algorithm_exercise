#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[505050];
long long acm[505050];
long long ldp[505050], ldp2[505050], rdp[505050];

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		acm[i] = acm[i-1] + arr[i];
	}

	// ldp[k]: k까지 봤을 때 acm의 최솟값
	// rdp[k]: n ~ n-k까지 봤을 때 acm의 최댓값
	// ldp2[k]: k까지 봤을 때 부분합의 최댓값
  ldp[0] = 2000000000;
	for (int i = 1; i <= n; ++i) {
		ldp[i] = min(ldp[i-1], acm[i]);
		ldp2[i] = max(ldp2[i-1], acm[i] - ldp[i]);
	}

	rdp[n+1] = -2000000000;
  for (int i = n; i > 0; --i) {
    rdp[i] = max(rdp[i+1], acm[i]);
  }

	long long res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(ldp2[i] + rdp[i+1] - acm[i], res);
	}

	cout << res + acm[n];
}

