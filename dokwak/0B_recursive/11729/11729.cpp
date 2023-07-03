#include <bits/stdc++.h>
using namespace std;
static vector<int> dp(50001, INT_MIN);

int	get_count(int disk_num)
{
	int ret = 0;
	if (disk_num == 1)
		return (1);
	return (get_count(disk_num - 1) + 1 + get_count(disk_num - 1));
}
void	hanoi(int start_pillar, int dest_pillar, int disk_num)
{
	if (disk_num == 1)
		cout << start_pillar << " " << dest_pillar << "\n";
	else
	{
		hanoi(start_pillar, 6 - start_pillar - dest_pillar, disk_num - 1);
		cout << start_pillar << " " << dest_pillar << "\n";
		hanoi(6 - start_pillar - dest_pillar, dest_pillar, disk_num - 1);
	}

}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	a;
	int	mov_num = 0;

	cin >> a;
	cout << get_count(a) << "\n";
	hanoi(1, 3, a);
	return (0);
}

