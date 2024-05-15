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
	string buf;
	unordered_set<string> cro;
	cro.insert("c=");
	cro.insert("c-");
	cro.insert("dz=");
	cro.insert("d-");
	cro.insert("lj");
	cro.insert("nj");
	cro.insert("s=");
	cro.insert("z=");
	vector<string> croatian(cro.begin(), cro.end());
	cin >> buf;
	int num = buf.size();
	int i = -1;
	while (++i < buf.size()){
		for (int j = 0; j < croatian.size(); j++) {
			if (i + croatian[j].size() - 1 < buf.size() && buf.compare(i, croatian[j].size(), croatian[j]) == 0) {
//				cout << "found : " << croatian[j]<<"\n";
//				cout << "str in buf : " << buf.substr(i, croatian[j].size())<<"\n";
				num -= (croatian[j].size() - 1);
				i += croatian[j].size() - 1;
			}
		}
	}
	cout << num;
	return (0);
}

