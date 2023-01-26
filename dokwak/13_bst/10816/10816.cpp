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
//int BST_NUM(int target)
//{
//	return (0);
//}

int BST_NUM(int target)
{
	int start = 0;
	int end = n - 1;
	int middle = (start + end) / 2;
	int find = 0;
	int most_left, most_right;
	//find most left index;
	//cout << target << " is target\n";
	while (!find && start <= end)
	{
		middle = (start + end) / 2;
		if (target == arr[start] || target == arr[end])
		{
			find = 1;
//			cout << "start : " << start << "\n";
//			cout << "end : " << end << "\n";
//			cout << "arr[start] : " << arr[start] << "\n";
//			cout << "arr[end] : " << arr[end] << "\n";
			break ;
		}
		if (end - start <= 1)
			return (0);
		if (target >= arr[middle])
			start = middle;
		else if (target < arr[middle])
			end = middle - 1;
	}
	while (arr[start] != target && start < end)
		start++;
	while (arr[end] != target && start < end)
		end--;
	while (start > 0 && arr[start] == target)
		start--;
	while (end < n - 1 && arr[end] == target)
		end++;
//	cout << "end widing, start, arr[start] : "
//		<< start
//		<< ", "
//		<< arr[start]
//		<< " end, arr[end] : "
//		<< end 
//		<< ", "
//		<< arr[end]
//		<< "\n";
	if (arr[end] == arr[start] == target)
		return (end - start + 1);
	else if ((arr[end] == target && arr[start] != target) || (arr[end] != target && arr[start] == target))
		return (end - start);
	else if (arr[end] != target && arr[start] != target)
		return (end - start - 1);
//	cout << "no element!\n";
	return (0);
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
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << "\n";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;
		cout << BST_NUM(target) << "\n";
	}
	return (0);
}
