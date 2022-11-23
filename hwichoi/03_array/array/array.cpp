#include <bits/stdc++.h>
using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	return (0);
}

int	func2(int *arr, int n) // arr의 각 수는 1부터 100, n은 1000 이하
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] + arr[j] == 100)
				return (1);
		}
	}
	return (0);
}

int	func2_mod(int *arr, int n)
{
	int num[101] = {};
	for (int i = 0; i < n; i++) {
		if (num[100 - arr[i]] == 1)
			return (1);
		num[arr[i]] = 1;
	}
	return (0);
}
