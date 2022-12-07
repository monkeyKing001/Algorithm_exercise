#include <bits/stdc++.h>
using namespace std;
int	n, m, stick_num;
int	**note;
int **sticker;
pair <int, int> start;
void find_vac()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (note[i][j] == 0)
			{
				start.first = i;
				start.second = j;
			}
		}
	}
}
void put_sticker(int w, int h)
{
	find_vac();
	// 0 degree
	int find_position = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (note[i][j] == 1 && sticker[i][j] == 1) //invalid
				break ;
			if (i == h - 1 && j == w - 1)
				find_position = 1;
		}
	}
	// 90 degree
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
		}
	}
	// 180 degree
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
		}
	}
	// 270 degree
	for (int i = ; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> stick_num;
	//make note
	note = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
		note[i] = (int *)malloc(sizeof(int) * m);
	memset(note, 0, n * m);

	for (int i = 0; i < stick_num; i++)
	{
		//input sticker
		int h, w;
		cin >> h >> w;
		sticker = (int **)malloc(sizeof(int *) * h);
		for (int j = 0; j < h; j++)
		{
			sticker[j] = (int *)malloc(sizeof(int) * w);
			for (int k = 0; k < w; k++)
				cin >> sticker[j][k];
		}
		//put sticker
		//free
	}
	return (0);
}

