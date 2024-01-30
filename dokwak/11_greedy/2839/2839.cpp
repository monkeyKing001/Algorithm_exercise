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
int five = 5, three = 3;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int boxFive = n / five;
	while (boxFive >= 0){
		int left = n  - (five * boxFive);
		if (left % three == 0){
			cout << (boxFive + (left / 3));
			return (0);
		}
		boxFive--;
	}
	cout << -1;
	return (0);
}

