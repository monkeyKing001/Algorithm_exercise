#include <bits/stdc++.h>
using namespace std;
int	n, m;

void	output(char *str)
{
	for (int i = 0; i < m; i++)
		cout << str[i] << " ";
	cout << "\n";
}
void	rec(char *str, int idx)
{
	int chk;
	if (idx == m)
	{
		output(str);
		return ;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			//cout << "num : " << i << endl;
			for (chk = idx - 1; chk > -1; chk--)
			{
				if (str[chk] == i + '0')
					break ;
			}
			if (chk == -1)
			{
				str[idx] = i + '0';
			//	cout << "idx : " << idx << endl;
				rec(str, idx + 1);
			}
		}
	}
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	char	*str = (char *)malloc(sizeof(char) * 9);
	rec(str, 0);
	return (0);
}
