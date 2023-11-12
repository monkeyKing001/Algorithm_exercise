#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int arr[100002];

bool bin_search(int input){
	int st = 0;
	int en = n-1;
	while (st <= en) {
		int mid = (st+en)/2;
		if (input < arr[mid]) en = mid-1;
		else if (input > arr[mid]) st = mid+1;
		else return 1;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int input;
		cin >> input;
		if (binary_search(arr, arr+n, input)) cout << "1\n";
		else cout << "0\n";
	}
	return (0);
}

