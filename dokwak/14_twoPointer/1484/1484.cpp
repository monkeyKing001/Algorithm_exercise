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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> sol;
	int g = 0;
	cin >> g;
	int b = 1;
	int a = sqrt(g);
	while (a + b <= 100000){
		int asq = a * a;
		int bsq = b * b;
		if (asq - bsq == g){
//			cout << "asq, bsq : " << asq << ", " << bsq << "\n";
//			cout << "asq - bsq : " << asq - bsq << "\n";
			sol.push_back(a);
			b++;
		}
		else if (asq - bsq > g)
			b++;
		else if (asq - bsq < g)
			a++;
	}
	if (sol.size() == 0){
		cout << -1;
		return (0);
	}
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << "\n";
	}
	return (0);
}

