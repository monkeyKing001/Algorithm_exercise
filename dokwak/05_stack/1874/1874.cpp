#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <stack>

using namespace std;
stack<int> A, B;
int n;
vector <char> buf;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	A.push(0);
	for (int i = 0; i < n; i++)
		B.push(n - i);
	for (int i = 0; i < n; i++)
	{
		int target;	
		cin >> target;
		if (A.top() > target)
		{
			cout << "NO\n";
			return (0);
		}
		while (A.top() < target)
		{
			A.push(B.top());
			B.pop();
			//cout << "+\n";
			buf.push_back('+');
		}
		if (A.top() == target)
		{
			//cout << A.top();
			//cout << "-\n";
			buf.push_back('-');
			A.pop();
		}
	}
	for (int i = 0; i < buf.size(); i++)
		cout << buf[i] << "\n";
	return (0);
}

