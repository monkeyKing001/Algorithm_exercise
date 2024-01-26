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
	string start, end, streamingEnd;
	cin >> start >> end >> streamingEnd;
	cin.ignore();
//	cout << start << ", "<< end << ", "<<streamingEnd << "\n";
	getline(cin, buf);
	set<string> come;
	int count = 0;
	while (buf.length() != 0){
		string time, name;
		stringstream ss(buf);
		getline(ss, time, ' ');
		getline(ss, name, ' ');
		if (time <= start){
//			cout << "name : " << name << "\n";
//			cout << "in time : " << time << "\n";
			come.insert(name);
		}
		else if (end <= time && time <= streamingEnd && come.find(name) != come.end()){
			count++;
//			cout << "out name : " << name << "\n";
			come.erase(name);
		}
		getline(cin, buf, '\n');
	}
	cout << count;
	return (0);
}

