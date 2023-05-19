/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2239.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:59:31 by dokwak            #+#    #+#             */
/*   Updated: 2023/05/14 17:25:12 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

void print_board(int board[10][10])
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
	exit(0);
}

void dfs(int input_board[10][10], int r, int c)
{
	int cur_r = r;
	int cur_c = c;
	int box_start_r = (((cur_r - 1) / 3) * 3) + 1;
	int box_start_c = (((cur_c - 1) / 3) * 3) + 1;
	int board[10][10];
	//copy
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			board[i][j] = input_board[i][j];
		}
	}
	//find proper num for the
	for (int i = 1; i < 10; i++)
	{
		int candidate = i;
		int pass = 1;
		//check row
		for (int row_temp = 1; row_temp < 10; row_temp++)
		{
			if (board[row_temp][cur_c] == candidate)
			{
				pass = 0;
				break; 
			}
		}
		//check col
		for (int col_temp = 1; col_temp < 10 && pass == 1; col_temp++)
		{
			if (board[cur_r][col_temp] == candidate)
			{
				pass = 0;
				break;
			}
		}
		//check box
		for (int temp_r = box_start_r; temp_r < box_start_r + 3 && pass == 1; temp_r++)
		{
			for (int temp_c = box_start_c; temp_c < box_start_c + 3 && pass == 1; temp_c++)
			{
				if (board[temp_r][temp_c] == candidate)
				{
					pass = 0;
					break;
				}
			}
		}
		if (pass) // candidate found!
		{
			board[cur_r][cur_c] = candidate;
//			cout << "board["
//				<< cur_r
//				<< "]["
//				<< cur_c
//				<< "] : "
//				<< candidate
//				<< "\n";
//			if (board[5][1] == 4)
//				print_board(board);
			//next step
			int next_r = cur_r;
			int next_c = 1;
			int find = 0;
			while (!find && next_r < 10)
			{
				if (next_r == cur_r)
					next_c = cur_c;
				else
					next_c = 1;
				while (!find && next_c < 10)
				{
//					cout << "checking next r, c : " << next_r <<", " << next_c << "\n";
					if (board[next_r][next_c] == 0)
					{
						find = 1;
						break;
					}
					next_c++;
				}
				if (find)
				{
					break;
//					cout << "next r, c : " << next_r << ", "<< next_c << "\n";
				}
				next_r++;
			}
			if (!find) //end dfs
				print_board(board);
			else //more dfs
				 dfs(board, next_r, next_c);
		}
		else//not proper candidate
		{
			board[cur_r][cur_c] = 0;
			continue ;
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int board[10][10];
	for (int i = 1; i < 10; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 1; j < 10; j++)
		{
			int num = temp[j - 1] - '0';
			board[i][j] = num;
		}
	}
	int start_r = 1;
	int start_c = 1;
	int find = 0;
	while (!find && start_r < 10)
	{
		while (!find && start_c < 10)
		{
			if (board[start_r][start_c] == 0)
			{
				find = 1;
				break;
			}
			start_c++;
		}
		if (find)
			break;
		start_r++;
	}
	dfs(board, start_r, start_c);
	return (0);
}
