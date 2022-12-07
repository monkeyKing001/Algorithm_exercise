#include <bits/stdc++.h>
using namespace std;
int	len;
vector <int> arr;
void	merge(int a_start, int a_end, int b_start, int b_end)
{
	int	*temp = (int *)malloc(sizeof(int) * (b_end - a_start + 1));
	int	a_i = a_start;
	int	b_i = b_start;
	int	temp_i = 0;
	if (b_i - a_i == 1)
	{
	}
	while (a_i <= a_end && b_i <= b_end)
	{
		if (arr[a_i] < arr[b_i])
			temp[temp_i++] = arr[a_i++];
		else if (arr[a_i] > arr[b_i])
			temp[temp_i++] = arr[b_i++];
//		else if (arr[a_i] == arr[b_i])
//		{
//			temp[temp_i++] = arr[a_i++];
//			temp[temp_i++] = arr[b_i++];
//		}
	}
	while (a_i <= a_end)
		temp[temp_i++] = arr[a_i++];
	while (b_i <= b_end)
		temp[temp_i++] = arr[b_i++];
	temp_i = -1;
	while (++temp_i < b_end - a_start + 1)
		arr[a_start + temp_i] = temp[temp_i];
	free(temp);
}

void	merge_sort(int start, int end)
{
	if (start == end)
		return ;
	else
	{
		int middle = (start + end) / 2;
		merge_sort(start, middle);
		merge_sort(middle + 1, end);
		merge(start, middle, middle + 1, end);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		int elm;
		cin >> elm;
		arr.push_back(elm);
	}
	merge_sort(0, len - 1);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	return (0);
}

