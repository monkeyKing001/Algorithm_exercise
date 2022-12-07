#include <bits/stdc++.h>
using namespace std;
vector <long long> arr_a;
vector <long long> arr_b;
vector <long long> merged_arr;
int	a_length;
int	b_length;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a_length >> b_length;
	int a_i = 0;
	int b_i = 0;

	for (a_i = 0; a_i < a_length; a_i++)
	{
		long long elm;
		cin >> elm;
		arr_a.push_back(elm);
	}
	for (b_i = 0; b_i < b_length; b_i++)
	{
		long long elm;
		cin >> elm;
		arr_b.push_back(elm);
	}
	a_i = 0;
	b_i = 0;
	while (a_i < a_length && b_i < b_length)
	{
		if (arr_a[a_i] < arr_b[b_i])
			merged_arr.push_back(arr_a[a_i++]);
		else if (arr_a[a_i] > arr_b[b_i])
			merged_arr.push_back(arr_b[b_i++]);
		else if (arr_a[a_i] == arr_b[b_i])
		{
			merged_arr.push_back(arr_a[a_i++]);
			merged_arr.push_back(arr_b[b_i++]);
		}
	}
	while (a_i < a_length)
		merged_arr.push_back(arr_a[a_i++]);
	while (b_i < b_length)
		merged_arr.push_back(arr_b[b_i++]);
	for (int i = 0; i < a_length + b_length; i++)
		cout << merged_arr[i] << " ";
	return (0);
}

