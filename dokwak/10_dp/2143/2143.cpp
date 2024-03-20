#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, n_a, n_b;
	map<int, int> aMap;
	cin >> T;
	cin >> n_a;
	vector<int> a(n_a, 0);
	vector<int> dpa(n_a, 0);
	for (int i = 0; i < n_a; i++) {
		cin >> a[i];
		if (i == 0)
			dpa[i] = a[i];
		else
			dpa[i] = dpa[i - 1] + a[i];
	}
	for (int i = 0; i < dpa.size(); i++) {
		for (int j = i; j < dpa.size(); j++) {
			int prefixSum = dpa[j] - dpa[i] + a[i];
			aMap[prefixSum]++;
		}
	}
	cin >> n_b;
	vector<int> b(n_b, 0);
	vector<int> dpb(n_b, 0);
	map<int, int> bMap;
	for (int i = 0; i < n_b; i++){
		cin >> b[i];
		if (i == 0)
			dpb[i] = b[i];
		else
			dpb[i] = dpb[i - 1] + b[i];
	}
	for (int i = 0; i < dpb.size(); i++) {
		for (int j = i; j < dpb.size(); j++) {
			int prefixSum = dpb[j] - dpb[i] + b[i];
			bMap[prefixSum]++;
		}
	}
	map<int, int>::iterator it = aMap.begin();
	long long allCase = 0;
	while (it != aMap.end()){
		int curNum = it -> first;
//		cout << curNum << " : " << it -> second << "\n";
		int restNum = T - curNum;
		if (bMap.find(restNum) != bMap.end()){
//			cout << restNum << " has been found :  " << bMap[restNum] << "\n";
			allCase += (long)it -> second * (long)bMap[restNum];
		}
		it++;
	}
	cout << allCase;
	return (0);
}

