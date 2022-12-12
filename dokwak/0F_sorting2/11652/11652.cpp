#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int n;
vector <int> input;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	//input
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	//stl sort
	sort(input.begin(), input.end());
	for (int i = 0; i < n; i++)
		cout << input[i] << " ";
	cout << "\n";
	return (0);
}

