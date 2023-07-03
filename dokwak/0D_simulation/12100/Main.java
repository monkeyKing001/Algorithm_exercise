import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int sol = -1;
	//diection 1 left 2 right 3 up 4 down
	public static void pb(int[][]board){
		System.out.println("print board");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}
	public static int left(int [][]board){
		int moved = 0;
		for (int i = 0; i < n; i++) {
			int start = 0;
			while (start < n - 1){
				int find = start + 1;
				while (find < n && board[i][find] == 0)
					find++;
				if (find < n && board[i][start] == board[i][find])
				{
					board[i][start] *= 2;
					board[i][find] = 0;
					start = find + 1;
					moved = 1;
				}
				else
					start = find;
			}
			int move_i = 0;
			int count = 0;
			while (count < n && board[i][count] != 0)
				count++;
			move_i = count + 1;
			while (move_i < n)
			{
				if (board[i][move_i] != 0)
				{
					board[i][count++] = board[i][move_i];
					board[i][move_i] = 0;
					moved = 1;
				}
				move_i++;
			}
		}
		return (moved);
	}
	public static int right(int [][]board){
		int moved = 0;
		for (int i = 0; i < n; i++) {
			int start = n - 1;
			while (start > 0){
				int find = start - 1;
				while (find > -1 && board[i][find] == 0)
					find--;
				if (find > -1 && board[i][start] == board[i][find])
				{
					board[i][start] *= 2;
					board[i][find] = 0;
					start = find - 1;
					moved = 1;
				}
				else
					start = find;
			}
			int move_i = 0;
			int count = n - 1;
			while (count > -1 && board[i][count] != 0)
				count--;
			move_i = count - 1;
			while (move_i > -1)
			{
				if (board[i][move_i] != 0)
				{
					board[i][count--] = board[i][move_i];
					board[i][move_i] = 0;
					moved = 1;
				}
				move_i--;
			}
		}
		return (moved);
	}
	public static int up(int [][]board){
		int moved = 0;
		for (int i = 0; i < n; i++) {
			int start = 0;
			while (start < n - 1){
				int find = start + 1;
				while (find < n && board[find][i] == 0)
					find++;
				if (find < n && board[start][i] == board[find][i])
				{
					board[start][i] *= 2;
					board[find][i] = 0;
					start = find + 1;
					moved = 1;
				}
				else
					start = find;
			}
			int move_i = 0;
			int count = 0;
			while (count < n && board[count][i] != 0)
				count++;
			move_i = count + 1;
			while (move_i < n){
				if (board[move_i][i] != 0)
				{
					board[count++][i] = board[move_i][i];
					board[move_i][i] = 0;
					moved = 1;
				}
				move_i++;
			}
		}
		return (moved);
	}
	public static int down(int [][]board){
		int moved = 0;
		for (int i = 0; i < n; i++) {
			int start = n - 1;
			while (start > 0){
				int find = start - 1;
				while (find > -1 && board[find][i] == 0)
					find--;
				if (find > -1 && board[start][i] == board[find][i])
				{
					board[start][i] *= 2;
					board[find][i] = 0;
					start = find - 1;
					moved = 1;
				}
				else
					start = find;
			}
			int move_i = 0;
			int count = n - 1;
			while (count > -1 && board[count][i] != 0)
				count--;
			move_i = count - 1;
			while (move_i > -1)
			{
				if (board[move_i][i] != 0)
				{
					board[count--][i] = board[move_i][i];
					board[move_i][i] = 0;
					moved = 1;
				}
				move_i--;
			}
		}
		return (moved);
	}
	public static void rec(int [][] board, int stage, int direction){
//		System.out.println("cur stage : " + stage);
		if (stage == 6)
		{
//			System.out.println("last stage : " + stage);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					sol = Integer.max(sol, board[i][j]);
				}
			}
			return ;
		}
//		System.out.println("before moving " + direction);
//		pb(board);
		int can_move = 0;
		switch (direction){
			case 0 :
				can_move = left(board);
				break;
			case 1 :
				can_move = right(board);
				break;
			case 2 :
				can_move = up(board);
				break;
			case 3 :
				can_move = down(board);
				break;
			default:
				break;
		}
		if (can_move == 0)
		{
//			System.out.println("## no more move : " + stage);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					sol = Integer.max(sol, board[i][j]);
				}
			}
			return ;
		}
//		System.out.println("after moving " + direction);
//		pb(board);
				
		//move as direction.
		for (int k = 0; k < 4; k++) {
			int [][]cp = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cp[i][j] = board[i][j];
				}
			}
			rec(cp, stage + 1, k);
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int [][]board = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < 4; i++) {
			int [][]cp = new int[n][n];
			for (int k = 0; k < n; k++) {
				for (int j = 0; j < n; j++) {
					cp[k][j] = board[k][j];
				}
			}
			rec(cp, 1, i);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
