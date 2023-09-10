#include <iostream>
using namespace std;

int	recur(int input)
{
	if (input < 1)
		return (0);
	else if (input == 1)
		return (1);
	else if (input == 2)
		return (2);
	else if (input == 3)
		return (4);
	return (recur(input - 1) + recur(input - 2) + recur(input - 3));
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;
	int	input;
	while (n--)
	{
		cin >> input;
		cout << recur(input) << '\n';
	}
	return (0);
}
