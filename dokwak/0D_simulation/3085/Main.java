import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		char[][] map = new char[n][n];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			map[i] = str.toCharArray();
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++){
				for (int d_i = 0; d_i < 4; d_i++) {
					int next_r = i + dr[d_i];
					int next_c = j + dc[d_i];
					//swap
					if (next_r < n && next_r > -1 && next_c < n && next_c > -1 && map[i][j] != map[next_r][next_c]){
						char[][] simulation = new char[n][n];
						//copy
						for (int r_i = 0; r_i < n; r_i++) {
							for (int c_i = 0; c_i < n ; c_i++){
								simulation[r_i][c_i] = map[r_i][c_i];
							}
						}
						char temp = simulation[i][j];
						simulation[i][j] = simulation[next_r][next_c];
						simulation[next_r][next_c] = temp;
						//now, count!
						//by row
						for (int r_i = 0; r_i < n; r_i++) {
							int l = 0;
							while (l < n){
								int r = l + 1;
								while (r < n && simulation[r_i][l] == simulation[r_i][r])
									r++;
								sol = Integer.max(sol, r - l);
								l = r;
							}
						}
						//by col
						for (int c_i = 0; c_i < n; c_i++) {
							int top = 0;
							while (top < n){
								int bottom = top + 1;
								while (bottom < n && simulation[top][c_i] == simulation[bottom][c_i])
									bottom++;
								sol = Integer.max(sol, bottom - top);
								top = bottom;
							}
						}
					}
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


