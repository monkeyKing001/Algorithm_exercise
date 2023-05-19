#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int N;
vector<int> v;
int first_s, second_s;
int opt = 1999999999;

void BS(int first_solution, int first_idx)
{
	int low = first_idx + 1;
	int high = v.size();

	while (low < high)
	{
		int mid = (low + high) / 2;

		if (abs(first_solution) <= v[mid])
			high = mid;

		else
			low = mid + 1;

		if (abs(first_solution + v[mid]) < abs(opt))
		{
			opt = first_solution + v[mid];
			first_s = first_solution;
			second_s = v[mid];
		}
	}
}

void Solve()
{
	for (int i = 0; i < v.size() - 1; i++)
		BS(v[i], i);

	cout << first_s << ' ' << second_s;
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		v.push_back(x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solve();

	return 0;
}
