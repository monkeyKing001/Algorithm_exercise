#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		int coin_count = 0;
		cin >> coin_count;
		vector<int> coins(coin_count, 0);
		for (int i = 0; i < coin_count; i++) 
			cin >> coins[i];
		int target_price;
		cin >> target_price;
		vector<vector<int>> dp_2d(coin_count, vector<int>(target_price + 1, 0));
		for (int coin_i = 0; coin_i < coin_count; coin_i++) {
			int coin_price = coins[coin_i];
			if (coin_i == 0){
				dp_2d[coin_i][coin_price] = 1;
				for (int price_i = coin_price + 1; price_i < target_price + 1; price_i++) 
					dp_2d[coin_i][price_i] = dp_2d[coin_i][price_i - coin_price];
			}
			else{
				for (int price_i = 1; price_i < target_price + 1; price_i++) {
					if (price_i < coin_price)
						dp_2d[coin_i][price_i] = dp_2d[coin_i - 1][price_i];
					else if (price_i == coin_price)
						dp_2d[coin_i][price_i] = dp_2d[coin_i - 1][price_i] + 1;
					else {
						dp_2d[coin_i][price_i] = dp_2d[coin_i - 1][price_i] + dp_2d[coin_i][price_i - coin_price];
					}
				}
			}
		}
//		for (int i = 0; i < coin_count; i++) {
//			for (int j = 1; j <= target_price; j++) {
//				cout << dp_2d[i][j] << " ";
//			}
//			cout << "\n";
//		}
		cout << dp_2d[coin_count - 1][target_price] << "\n";
	}
	return (0);
}

