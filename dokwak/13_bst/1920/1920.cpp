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

//barking dog BST
//int BST(int target)
//{
//	int start = 0;
//	int end = arr.size() - 1;
//	int middle = (start + end) / 2;
//	while (start <= end)
//	{
//		middle = (start + end) / 2;
//		if (arr[middle] < target)
//			start = middle + 1;
//		else if (arr[middle] > target)
//			end = middle - 1;
//		else
//			return (1);
//	}
//	return (0);
//}

int	BST(int target)
{
	//left half
	int end = arr.size() - 1 ;
	int middle = arr.size() / 2;
	int start = 0;
	int find = 0;
	while (!find)
	{
		if (target < arr[start] || target > arr[end] || start > end)
			return (0);
		if (target == arr[start] || target == arr[end] || target == arr[middle])
			return (1);
		if (end - start <= 2)
			return (0);
		if (target >= arr[middle])
		{
			start = middle;
			middle = (start + end) / 2;
		}
		else
		{
			end = middle - 1;
			middle = (start + end) / 2;
		}
	}
	//right half
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
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int target;
		cin >> target;
		//Binary Search Tree start!
		cout << BST(target) << "\n";
	}
	return (0);
}

