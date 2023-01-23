#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int n;
vector <long long> input;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	//input
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		input.push_back(temp);
	}

	//stl sort
	sort(input.begin(), input.end());
//	for (int i = 0; i < n; i++)
//		cout << input[i] << " ";
//	cout << "\n";
	long long cnt, mx_num;
	mx_num = input[0];
	cnt = 0;
	int j = 0;
	while (j < n)
	{
		long long temp_cnt = 1;
		while (j + 1 < n && input[j] == input[j + 1])
		{
			temp_cnt++;
			j++;
		}
		if (temp_cnt > cnt)
		{
			cnt = temp_cnt;
			mx_num = input[j];
		}
		j++;
	}
	cout << mx_num << "\n";
	return (0);
}
