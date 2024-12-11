#include <bits/stdc++.h>

using namespace std;
int n, m, max_len;
bool possible(vector<int> &stations, int interval){
	int prv_station = 0;
	int more_stations = m;
	for (auto s: stations){
		while (s - prv_station > interval && more_stations > 0) prv_station += interval, more_stations--;
		if (s - prv_station > interval) return false;
		prv_station = s;
	}
	return true;
} 

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> max_len;
	vector<int> stations(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> stations[i];
	stations.back() = max_len;
	sort(stations.begin(), stations.end());
	int l = 1, r = max_len;
	int sol = INT_MAX;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(stations, mid))
			r = mid - 1, sol = mid;
		else
			l = mid + 1;
	}
	cout << sol;
	return (0);
}

