#include <bits/stdc++.h>
using namespace std;
int	n, m, cctv_num;
int	dead = 0;
int	**room;
int	dr[4] = {0, -1, 0, 1};
int	dc[4] = {-1, 0, 1, 0};
void rotate_cctv(int cctv_idx, int len, int **room_case);
int	**cp_matrix(int **src)
{
	int	**ret = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		ret[i] = (int *)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++)
			ret[i][j] = src[i][j];
	}
	return (ret);
}

void free_mat(int **src)
{
	for (int i = 0; i < n; i++)
		free(src[i]);
}

void update_min_dead(int **room_case)
{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << room_case[i][j] << " ";
//		cout << endl;
//	}
//	cout << "--------------------\n";
	int	temp_dead = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (room_case[i][j] == 0)
				temp_dead++;
	if (temp_dead < dead)
		dead = temp_dead;
}

void rotate_1(int cctv_idx, int cctv_r, int cctv_c, int **room_case, int dir_i, int len)
{
	if (cctv_idx == cctv_num)
	{
		update_min_dead(room_case);
		free_mat(room_case);
		free(room_case);
	}
	int	offset = 1;
	int mov_r = dr[dir_i] * offset;
	int mov_c = dc[dir_i] * offset;
	while (cctv_r + mov_r >= 0 && cctv_r + mov_r < n && cctv_c + mov_c >= 0 && cctv_c + mov_c < m)
	{
		if (room_case[cctv_r + mov_r][cctv_c + mov_c] == 6)
			break ;
		if (room_case[cctv_r + mov_r][cctv_c + mov_c] >= 1 && room_case[cctv_r + mov_r][cctv_c + mov_c] <= 5)
		{
			offset++;
			mov_r = dr[dir_i] * offset;
			mov_c = dc[dir_i] * offset;
			continue ;
		}
		room_case[cctv_r + mov_r][cctv_c + mov_c] = -1;
		offset++;
		mov_r = dr[dir_i] * offset;
		mov_c = dc[dir_i] * offset;
	}
	rotate_cctv(cctv_idx + 1, len + 1, room_case);
}

void rotate_2(int cctv_idx, int cctv_r, int cctv_c, int **room_case, int dir_i, int len)
{
	if (cctv_idx == cctv_num)
	{
		update_min_dead(room_case);
		free_mat(room_case);
		free(room_case);
	}
	for (int i = 0; i < 4; i = i + 2)
	{
	int	offset = 1;
	int mov_r = dr[(dir_i + i) % 4] * offset;
	int mov_c = dc[(dir_i + i) % 4] * offset;
	while (cctv_r + mov_r >= 0 && cctv_r + mov_r < n && cctv_c + mov_c >= 0 && cctv_c + mov_c < m)
		{
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] == 6)
				break ;
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] >= 1 && room_case[cctv_r + mov_r][cctv_c + mov_c] <= 5)
			{
				offset++;
				mov_r = dr[(dir_i + i) % 4] * offset;
				mov_c = dc[(dir_i + i) % 4] * offset;
				continue ;
			}
	//		cout << cctv_r + mov_r
	//			<< ", "
	//			<< cctv_c + mov_c
	//			<< " = -1\n";
			room_case[cctv_r + mov_r][cctv_c + mov_c] = -1;
			offset++;
			mov_r = dr[(dir_i + i) % 4] * offset;
			mov_c = dc[(dir_i + i) % 4] * offset;
		}
	}
	rotate_cctv(cctv_idx + 1, len + 1, room_case);
}

void rotate_3(int cctv_idx, int cctv_r, int cctv_c, int **room_case, int dir_i, int len)
{
	if (cctv_idx == cctv_num)
	{
		update_min_dead(room_case);
		free_mat(room_case);
		free(room_case);
	}
//	cout << cctv_r << ", "<< cctv_c << " rot 2\n";
	for (int i = 0; i < 2; i++)
	{
	int	offset = 1;
	int mov_r = dr[(dir_i + i) % 4] * offset;
	int mov_c = dc[(dir_i + i) % 4] * offset;
	while (cctv_r + mov_r >= 0 && cctv_r + mov_r < n && cctv_c + mov_c >= 0 && cctv_c + mov_c < m)
		{
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] == 6)
				break ;
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] >= 1 && room_case[cctv_r + mov_r][cctv_c + mov_c] <= 5)
			{
				offset++;
				mov_r = dr[(dir_i + i) % 4] * offset;
				mov_c = dc[(dir_i + i) % 4] * offset;
				continue ;
			}
	//		cout << cctv_r + mov_r
	//			<< ", "
	//			<< cctv_c + mov_c
	//			<< " = -1\n";
			room_case[cctv_r + mov_r][cctv_c + mov_c] = -1;
			offset++;
			mov_r = dr[(dir_i + i) % 4] * offset;
			mov_c = dc[(dir_i + i) % 4] * offset;
		}
	}
	rotate_cctv(cctv_idx + 1, len + 1, room_case);
}

void rotate_4(int cctv_idx, int cctv_r, int cctv_c, int **room_case, int dir_i, int len)
{
	if (cctv_idx == cctv_num)
	{
		update_min_dead(room_case);
		free_mat(room_case);
		free(room_case);
	}
	for (int i = 0; i < 3; i++)
	{
	int	offset = 1;
	int mov_r = dr[(dir_i + i) % 4] * offset;
	int mov_c = dc[(dir_i + i) % 4] * offset;
	while (cctv_r + mov_r >= 0 && cctv_r + mov_r < n && cctv_c + mov_c >= 0 && cctv_c + mov_c < m)
		{
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] == 6)
				break ;
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] >= 1 && room_case[cctv_r + mov_r][cctv_c + mov_c] <= 5)
			{
				offset++;
				mov_r = dr[(dir_i + i) % 4] * offset;
				mov_c = dc[(dir_i + i) % 4] * offset;
				continue ;
			}
	//		cout << cctv_r + mov_r
	//			<< ", "
	//			<< cctv_c + mov_c
	//			<< " = -1\n";
			room_case[cctv_r + mov_r][cctv_c + mov_c] = -1;
			offset++;
			mov_r = dr[(dir_i + i) % 4] * offset;
			mov_c = dc[(dir_i + i) % 4] * offset;
		}
	}
	rotate_cctv(cctv_idx + 1, len + 1, room_case);
}

void see_5(int cctv_idx, int cctv_r, int cctv_c, int **room_case, int len)
{
	if (cctv_idx == cctv_num)
	{
		update_min_dead(room_case);
		free_mat(room_case);
		free(room_case);
	}
	for (int dir_i = 0; dir_i < 4; dir_i++)
	{
		int	offset = 1;
		int mov_r = dr[dir_i] * offset;
		int mov_c = dc[dir_i] * offset;
//		cout << "from " << cctv_r << ", " << cctv_c;
		while (cctv_r + mov_r >= 0 && cctv_r + mov_r < n && cctv_c + mov_c >= 0 && cctv_c + mov_c < m)
		{
//			cout
//				<< " checking "
//				<< cctv_r + mov_r
//				<<", "
//				<< cctv_c + mov_c
//				<< endl;
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] == 6)
				break ;
			if (room_case[cctv_r + mov_r][cctv_c + mov_c] >= 1 && room_case[cctv_r + mov_r][cctv_c + mov_c] <= 5)
			{
				offset++;
				mov_r = dr[dir_i] * offset;
				mov_c = dc[dir_i] * offset;
				continue ;
			}
//			cout << cctv_r + mov_r
//				<< ", "
//				<< cctv_c + mov_c
//				<< " = -1\n";
			room_case[cctv_r + mov_r][cctv_c + mov_c] = -1;
			offset++;
			mov_r = dr[dir_i] * offset;
			mov_c = dc[dir_i] * offset;
		}
	}
	rotate_cctv(cctv_idx + 1, len + 1, room_case);
}

void rotate_cctv(int cctv_idx, int len, int **room_case)
{
	int **cp;

	if (cctv_idx == cctv_num)
		update_min_dead(room_case);
	else
	{
		int now_r = len / m;
		int	now_c = len % m;
		while (len < (n * m) && (room_case[now_r][now_c] == 0 || room_case[now_r][now_c] == -1 || room_case[now_r][now_c] == 6))
		{
			len++;
			now_r = len / m;
			now_c = len % m;
		}
		if (room_case[now_r][now_c] == 1)
		{
			for (int dir_i = 0; dir_i < 4; dir_i++)
			{
				cp = cp_matrix(room_case);
				rotate_1(cctv_idx, now_r, now_c, cp, dir_i, len);
				free_mat(cp);
				free(cp);
			}
		}
		else if (room_case[now_r][now_c] == 2)
		{
			for (int dir_i = 0; dir_i < 2; dir_i++)
			{
				cp = cp_matrix(room_case);
				rotate_2(cctv_idx, now_r, now_c, cp, dir_i, len);
				free_mat(cp);
				free(cp);
			}
		}
		else if (room_case[now_r][now_c] == 3)
		{
			for (int dir_i = 0; dir_i < 4; dir_i++)
			{
				cp = cp_matrix(room_case);
				rotate_3(cctv_idx, now_r, now_c, cp, dir_i, len);
				free_mat(cp);
				free(cp);
			}
		}
		else if (room_case[now_r][now_c] == 4)
		{
			for (int dir_i = 0; dir_i < 4; dir_i++)
			{
				cp = cp_matrix(room_case);
				rotate_4(cctv_idx, now_r, now_c, cp, dir_i, len);
				free_mat(cp);
				free(cp);
			}
		}
		else if (room_case[now_r][now_c] == 5)
			see_5(cctv_idx, now_r, now_c, room_case, len);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	room = (int **)malloc(sizeof(int *) * n );
	for (int i = 0; i < n; i++)
	{
		room[i] = (int *)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++)
		{
			int	obj;
			cin >> obj;
			if (obj >= 1 & obj <= 5)
				cctv_num++;
			if (obj == 0)
				dead++;
			room[i][j] = obj;
		}
	}
	if (dead == 0)
	{
		cout << 0;
		return (0);
	}
	if (cctv_num == 0)
	{
		cout << dead;
		return (0);
	}
	rotate_cctv(0, 0, room);
	cout << dead;
	return (0);
}
