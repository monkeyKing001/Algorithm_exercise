#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick(int st, int en) {
	if (st+1 == en || st == en) return;
	int pivot = st;
	int l = st+1;
	int r = en-1;
	while(1) {
		while (l <= r && arr[pivot] >= arr[l]) l++;
		while (l <= r && arr[pivot] <= arr[r]) r--;
		if (l > r) break;
		swap(arr[l], arr[r]);
	}
	swap(arr[r], arr[pivot]);
	quick(st, r);
	quick(r+1, en);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	quick(0, 8);
	for (int i = 0; i < 8; ++i) cout << arr[i] << ' ';
	return (0);
}
