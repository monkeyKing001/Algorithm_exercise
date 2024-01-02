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
	string strA;
	string strB;
	cin >> strA;
	cin >> strB;
	int A_i = strA.length() - 1;
	int B_i = strB.length() - 1;
	string buf = "";
	int upper = 0;
	while (A_i >= 0 && B_i >= 0){
		int a = strA[A_i] - '0';
		int b = strB[B_i] - '0';
		int aPb = a + b + upper;
		upper = 0;
		if (aPb >= 10)
			upper = 1;
		aPb %= 10;
		char aPb_chr = aPb + '0';
		A_i--;
		B_i--;
		buf = aPb_chr + buf;
	}
	while (A_i >= 0){
		int a = strA[A_i] - '0' + upper;
		upper = 0;
		if (a >= 10)
			upper = 1;
		a %= 10;
		char a_chr = a + '0';
		buf = a_chr + buf;
		A_i--;
	}
	while (B_i >= 0){
		int b = strB[B_i] - '0' + upper;
		upper = 0;
		if (b >= 10)
			upper = 1;
		b %= 10;
		char b_chr = b + '0';
		buf = b_chr + buf;
		B_i--;
	}
	if (upper == 1){
		buf = '1' + buf;
	}
	cout << buf + "\n"; 
	return (0);
}

