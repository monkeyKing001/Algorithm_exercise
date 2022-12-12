#include <iostream>
using namespace std;
int counting[2000001];
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		counting[temp + 1000000]++;
	}
	for (int i = 0; i < 2000001; i++)
	{
		while (counting[i]--)
			cout << i - 1000000 << "\n";
	}
	return (0);
}

