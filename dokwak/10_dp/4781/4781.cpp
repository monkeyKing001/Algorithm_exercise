#include <bits/stdc++.h>

using namespace std;
int n, m;

//int main()
//{
//    for (double i = 0.01; i <= 10.; i += 0.01)
//        cout << i << " " << int(i * 100 + 0.5f) << '\n';
//}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double budget;
	int offset = 100;
	cin >> n >> budget;
	while (n != 0 && budget != 0.0){
		int budget_int = budget * offset;
		vector<int> dp(budget_int + 1, 0);
		for (int i = 0; i < n; i++) {
			int cal;
			double p;
			cin >> cal >> p;
			int p_int = (int)(p * offset + 0.5f);
			for (int j = p_int; j < budget_int + 1; j++) {
				dp[j] = max(dp[j], dp[j - p_int] + cal);
			}
		}
		cout << dp[budget_int] << "\n";
		cin >> n >> budget;
	}
	return (0);
}

