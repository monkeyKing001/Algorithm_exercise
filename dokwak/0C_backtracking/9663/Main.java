import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static boolean visited[][];
	static int sol = 0;
	static boolean valid(int q_i, int position_i){
		//row horizontal check
		for (int check_i = 0; check_i < q_i; check_i++) {
			if(visited[position_i][check_i])
				return (false);
		}
		//diagonal check check
		for (int diagonal_len = 1; diagonal_len < n; diagonal_len++) {
			if (q_i - diagonal_len >= 0 && 
					position_i - diagonal_len >= 0 &&
					visited[position_i - diagonal_len][q_i - diagonal_len])
				return (false);
			if (q_i - diagonal_len >= 0 &&
					position_i + diagonal_len < n &&
					visited[position_i + diagonal_len][q_i - diagonal_len])
				return (false);
		}
		return (true);
	}

	static void rec(int q_i){
		if (q_i == n){
			sol++;
			return;
		}
		for (int position_i = 0; position_i < n; position_i++) {
			if (valid(q_i, position_i)) {
				visited[position_i][q_i] = true;
				rec(q_i + 1);
				visited[position_i][q_i] = false;
			}
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
		visited = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++){
				visited[i][j] = false;
			}
		}
		rec(0);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
