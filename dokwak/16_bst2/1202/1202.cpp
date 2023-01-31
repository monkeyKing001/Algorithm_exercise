#include <functional>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <set>
#include <string>

using namespace std;
bool	cmp(pair<int, int> a, pair<int, int> b)
{
//	return (a.second / a.first > b.second / b.first);
	return (a.second > b.second);
}

bool cmp2(int a, int b)
{
	return (a < b);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long total;
	multiset <int> bags;
//	multimap<int , int, greater<int>>j;
	vector<pair <int, int> >j;
	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		j.push_back(make_pair(m, v));
	}
//	for (int i = 0; i < n; i++)
//		cout << j[i].first << ", " << j[i].second << "\n";
//	for (int i = 0; i < n; i++)
//		cout << j[i].first << ", " << j[i].second << "\n";
	for (int i = 0; i < k; i++)
	{
		int max_c;
		cin >> max_c;
//		cout << max_c << "\n";
		bags.insert(max_c);
	}
	sort(j.begin(), j.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		int jewl_m = j[i].first;
		auto it = bags.lower_bound(jewl_m);
		if (it == bags.end()) continue;
		else
		{
			total += j[i].second;
			bags.erase(it);
		};
	}
	cout << total << "\n";
	return (0);
}

