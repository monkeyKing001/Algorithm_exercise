#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int MaximizeEqualNumbers(int n, int k, vector<int> a)
{
	//write your code here
	sort(a.begin(), a.end());
	int min = a[0] - k - 3;
	int max = a[n -1] + k + 3;
	int len = max - min;
	int offset = abs(min);
	int max_sequence = 0;
	vector <int> group(len);
	fill_n(group.begin(), len, 0);
	for (int i = 0; i < n; i++)
	{
		int temp_num = a[i] + offset;
		group[temp_num]++;
//		cout << a[i] << " can be from " << a[i] - k
//			<< " to " << a[i] + k <<"\n";
		for (int j = 1; j <= k; j++)
		{
			group[temp_num + j]++;
			group[temp_num - j]++;
		}
	}
	for (int i = 0; i < len; i++)
	{
		int decod = i - offset;
//		cout << decod << " can be appeared " << group[i] << " times\n";
		if (group[i] > max_sequence)
			max_sequence = group[i];
	}
	return (max_sequence);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++)
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		vector <int> a(n);
		for (int i_a = 0; i_a < n; i_a++)
			cin >> a[i_a];
		cout << MaximizeEqualNumbers(n, k, a);
		cout << "\n";
	}
	return (0);
}

