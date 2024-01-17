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
	string r1, r2;
	cin >> r1 >> r2;
	map<string,int> rtoi;
	map<int,string> itor;
	rtoi["I"] = 1;rtoi["II"] = 2;rtoi["III"] = 3;rtoi["IV"] = 4;rtoi["V"] = 5;
	rtoi["VI"] = 6;rtoi["VII"] = 7;rtoi["VIII"] = 8;rtoi["IX"] = 9;
	rtoi["X"] = 10;rtoi["XX"] = 20;rtoi["XXX"] = 30;rtoi["XL"] = 40;rtoi["L"] = 50;
	rtoi["LX"] = 60;rtoi["LXX"] = 70;rtoi["LXXX"] = 80;rtoi["XC"] = 90;
	rtoi["C"] = 100;rtoi["CC"] = 200;rtoi["CCC"] = 300;rtoi["CD"] = 400;rtoi["D"] = 500;
	rtoi["DC"] = 600;rtoi["DCC"] = 700;rtoi["DCCC"] = 800;rtoi["CM"] = 900;
	rtoi["M"] = 1000; rtoi["MM"] = 2000;rtoi["MMM"] = 3000;
	map<string,int>::iterator it = rtoi.begin();
	while (it != rtoi.end()){
		string rome = it->first;
		int num = it->second;
		itor[num] = rome;
		it++;
	}
	int l = 0;
	int num1 = 0;
	while (l < r1.length()){
		int r = l + 1;
		while (r <= r1.length()){
			string temp = r1.substr(l, r - l);
			if (rtoi.find(temp) == rtoi.end())
				break;
			r++;
		}
		string token = r1.substr(l, r - l - 1);
		num1 += rtoi[token];
		l = r - 1;
	}
//	cout << num1 << "\n";
	l = 0;
	int num2 = 0;
	while (l < r2.length()){
		int r = l + 1;
		while (r <= r2.length()){
			string temp = r2.substr(l, r - l);
			if (rtoi.find(temp) == rtoi.end())
				break;
			r++;
		}
		string token = r2.substr(l, r - l - 1);
		num2 += rtoi[token];
		l = r - 1;
	}
//	cout << num2 << "\n";
	int sum = num1 + num2;
	string sumString = to_string(sum);
	string sumRome = "";
	int base = pow(10, sumString.length() - 1);
	while (base != 0){
		int temp = (sum / base) * base;
		sumRome += itor[temp];
		sum -= temp;
		base /= 10;
	}
	cout << sumString << "\n";
	cout << sumRome << "\n";
	return (0);
}
