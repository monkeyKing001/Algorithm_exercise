#include <bits/stdc++.h>
using namespace std;
int	N, r, c;
int	mov_num = 0;
int	dr[4] = {0, 0, 1, 1};
int	dc[4] = {0, 1, 0, 1};
// be caution for time over.
// recursion only when it needs.
void visit(int size_N, int start_r, int start_c, int mov_num)
{
//	cout << "start point = "
//		<< start_r 
//		<< ", " 
//		<< start_c 
//		<< " size = " 
//		<< size_N 
//		<< " start_mov_num = "
//		<< mov_num
//		<< endl;
	int next_size = 1 << (size_N - 1);
	int	current_size = 1 << size_N;
	if (size_N == 1)
	{
		if ((r - start_r >= 0 && r - start_r <= 1) && (c - start_c >= 0 && c - start_c <= 1))
		{
			for (int i = 0 ; i < 4; i++)
			{
				if (start_r + dr[i] == r && start_c + dc[i] == c)
					cout << mov_num + i << endl;
			}
		}
	}
	if (size_N > 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int next_r = start_r + dr[i] * next_size;
			int next_c = start_c + dc[i] * next_size;
			if (next_r <= r && r < next_r + next_size && next_c <= c && c < next_c + next_size)
				visit(size_N - 1, next_r, next_c, mov_num + next_size  * next_size * i);
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;
	visit(N, 0, 0, mov_num);
	return (0);
}
