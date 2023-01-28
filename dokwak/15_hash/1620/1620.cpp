#include <exception>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> m1;
//	map<int, string> m1;
	unordered_map<string, int> m2;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		m1.push_back(temp);
		m2[temp] = i;
//		cout << m1[i] << "\n";
//		cout << m2[temp] << "\n";
	}
	char *end;
	double value;
	int		num;
	for (int i = 0; i < m; i++)
	{
		string input;
		cin >> input;
		try {
			int x = std::stoi(input);
			cout << m1[x - 1] << "\n";
		}catch(exception &e) {
			cout << m2[input] + 1 << "\n";
		}
	}
	return (0);
}

