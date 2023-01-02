#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>

using namespace std;
int n, k;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vector <int> coins(n+1, 0);
	int sum = 0;
	int coin_num = 0;
	int coin_index = n - 1;
	for (int i = 0; i < n; ++i) 
	{
		int val;
		cin >> val;
		coins[i] = val;
	}
	while (sum < k && coin_index >= 0)
	{
		while (coins[coin_index] > k - sum)
			coin_index--;
		while (sum < k)
		{
//			cout << "+= " << coins[coin_index] << endl;
			sum += coins[coin_index];
			coin_num++;
			if (sum == k || coins[coin_index] > k - sum)
			{
//				cout << "break!\nsum = " << sum << "\ncoins[coin_index] : " << coins[coin_index] << endl;
				break ;
			}
		}
	}
	cout << coin_num;
	return (0);
}

