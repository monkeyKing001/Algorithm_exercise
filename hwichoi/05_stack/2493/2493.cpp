#include <iostream>
#include <stack>
using namespace std;

int	main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int input, N;
	cin >> N;
	stack<pair<int, int>> s;
    s.push(make_pair(0, 0));
	for (int i = 1; i <= N; ++i) {
		cin >> input;
		while (s.top().second && s.top().first < input)
			s.pop();
		cout << s.top().second << " ";
		s.push(make_pair(input, i));
	}
	cout << endl;
	return (0);
}
