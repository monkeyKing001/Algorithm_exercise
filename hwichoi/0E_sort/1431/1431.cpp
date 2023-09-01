#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
string arr[52];

bool cmp(string &a, string &b) {
	if (a.length() != b.length()) return a.length() < b.length();
	int at = 0;
	int bt = 0;
	for (char c : a) {
		if (c >= '0' && c <= '9') at += c - '0';
	}
	for (char c : b) {
		if (c >= '0' && c <= '9') bt += c - '0';
	}
	if (at != bt) return at < bt;
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n, cmp);
	for (int i = 0; i < n; ++i) cout << arr[i] << '\n';
	return (0);
}

