#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int n;
bool comp(int a, int b)
{
	return (b < a);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> A, B;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		A.push_back(a);	
	}
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		B.push_back(b);	
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), comp);
	int sol = 0;
	for (int i = 0 ; i < n; i++)
		sol += A[i] * B[i];
	cout << sol;

	return (0);
}

