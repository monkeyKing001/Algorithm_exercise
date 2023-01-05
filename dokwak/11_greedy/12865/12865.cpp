#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
bool com_w(pair<int ,int> a, pair <int, int> b)
{
	return (b.first < a.first);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > jun;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		jun.push_back(make_pair(w, v));
	}
	sort(jun.begin(), jun.end(), com_w);
	for (int i = 0; i < n; i++)
		cout << "w, v : " << jun[i].first <<", " <<jun[i].second << endl;
	
	return (0);
}

