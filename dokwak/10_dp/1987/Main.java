import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int map[][];
	static int visited[][];
	static int sol = 0;
	static int[] dr = {0, 1, 0, -1};
	static int[] dc = {1, 0, -1, 0};
	public static void rec(int cur_r, int cur_c, int bits){
		int count = 0;
//		System.out.println("cur r, c : " + cur_r +", "+ cur_c +" : "+ (char)(map[cur_r][cur_c] + 'A'));
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			if (next_r > -1 && next_r < n && next_c > -1 && next_c < m){
				if ((bits & (1 << map[next_r][next_c])) == 0)//not contained
				{
					rec(next_r, next_c, bits | (1 << map[next_r][next_c]));
					count++;
				}
			}
		}
		//count len
		if (count == 0)
		{
//			System.out.println("END Travel");
			int len = 0;
			for (int i = 0; i < 26; i++) {
				if (((bits >> i) % 2) == 1)//hit
					len++;
			}
			if (sol < len)
				sol = len;
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
		m = Integer.parseInt(st.nextToken());
		int bits = 0;
		map = new int [n][m];
		visited = new int [n][m];
		for (int i = 0; i < n; i++) {
			String str = br.readLine().toString();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j) - 'A';
				visited[i][j] = 0;
			}
		}
		bits = (bits | (1 << map[0][0]));
		rec(0, 0, bits);
		System.out.println(sol);
		return ;
	}
}
