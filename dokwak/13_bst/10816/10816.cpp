#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
vector <int> arr;
int BST_NUM(int target);

int BST_NUM(int target)
{
	vector<int>::iterator it_low;
	vector<int>::iterator it_up;
	it_low = lower_bound(arr.begin(), arr.end(), target);
	it_up = upper_bound(arr.begin(), arr.end(), target);
	if (*it_low != target)
		return (0);
	else
		return it_up - it_low;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;
		cout << BST_NUM(target) << "\n";
	}
	return (0);
}
