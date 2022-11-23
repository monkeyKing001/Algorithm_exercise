#include <bits/stdc++.h>
using namespace std;
int	n;
int	way = 0;
void	n_qn(int *board, int q_i)
{
	if (q_i == n)
		way++;
	else
	{
		int	chk_i = q_i - 1;
		for (int pos = 0; pos < n; pos++)
		{
			for(chk_i =  q_i - 1; chk_i > -1; chk_i--)
			{
				if (board[chk_i] == pos || pos - board[chk_i] == q_i - chk_i || pos - board[chk_i] == chk_i - q_i)
					break ;
			}
			if (chk_i == -1)
			{
				board[q_i] = pos;
				n_qn(board, q_i + 1);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int	*board;
	board = (int *)malloc(sizeof(int) * n);
	n_qn(board, 0);
	cout << way;
	return (0);
}

