#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int n, not_p_num;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> nums;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 0; i <= n; i++)
	{
		if (nums[i] == 1)
		{
			not_p_num++;
			continue ;
		}
		for (int j = 2; j * j < nums[i]; j++)
		{
			if (nums[i] % j == 0)	
			{
				not_p_num++;
				//cout << nums[i] <<" : not a prime number\n";
				break;
			}
		}
	}
	cout << n - not_p_num;
	return (0);
}

