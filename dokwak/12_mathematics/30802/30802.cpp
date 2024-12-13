#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> Tshirts(6, 0);
	cin >> n;
	sort(Tshirts.begin(), Tshirts.end());
	for (int i = 0; i < 6; i++) cin >> Tshirts[i];
	int T_bundle = 0;
	int Pen_bundle = 0;
	cin >> T_bundle >> Pen_bundle;
	int total_T_bundle = 0;
	int total_pen_bundle = 0;
	for (int i = 0; i < 6; i++) total_T_bundle += ceil((double)((double)Tshirts[i] / (double)T_bundle)); 
	cout << total_T_bundle << "\n" << n / Pen_bundle << " " << n % Pen_bundle;
	return (0);
}

