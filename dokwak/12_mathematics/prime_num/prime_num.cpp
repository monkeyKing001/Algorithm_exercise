#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	if (n == 1)
	{
		cout << "It is not prime number\n";
		return (0);
	}
	for (int i = 2; i * i < n; i++)
	{
		if ( n % i == 0 )	
		{
			cout << "It is not prime number\n";
			return (0);
		}
	}
	cout << "It is prime number\n";
	return (0);
}

