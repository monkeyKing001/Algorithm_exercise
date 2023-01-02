#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>

using namespace std;
int n, max_weight, current_weight;

bool comp(int r1, int r2)
{
	return (r2 < r1);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> ropes (n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int weight;
		cin >> weight;
		ropes[i] = weight;
	}
	int total_selected_num = 0;
	sort(ropes.begin(), ropes.end(), comp);
//	for (int i = 0; i < n; ++i)
//		cout << ropes[i] << endl;
	max_weight = ropes[1];
	total_selected_num = 1;
	for (int i = 1; i < n; ++i) {
		if (ropes[i] >= max_weight / total_selected_num)
		{
			total_selected_num++;
			max_weight = ropes[i] * total_selected_num;
		}
	}
	cout << max_weight;

	return (0);
}

