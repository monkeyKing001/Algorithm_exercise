#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;
typedef pair<double, double>P;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (-y1 * x2 - y2 * x3 - y3 * x1);
	return res / 2;
}

int main() {
	int n; cin >> n;
	vector<P>arr(n);

	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &arr[i].first, &arr[i].second);

	double res = 0;
	for (int i = 1; i < n; i++)
		res += ccw(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);

	printf("%.1lf", abs(res));
	return 0;
}
