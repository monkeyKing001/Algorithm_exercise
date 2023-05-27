import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int map[][];
	static int sol = 0;
	static int[] dr = {0, 1, 0, -1};
	static int[] dc = {1, 0, -1, 0};
	public static int count_one(int bits)
	{
		int ret = 0;
		for (int i = 0; i < 26; i++) {
			if ((1 << i & bits) != 0)//bit hits
				ret++;
		}
		return (ret);
	}
	public static void dfs(int cur_r, int cur_c, int bits)
	{
		//if cur no more progress, -> bit hits
		if ((bits & (1 << map[cur_r][cur_c])) != 0){
//			System.out.println("cannot progress! cur_r, cur_c : " + cur_r +", "+ cur_c);
			sol = Integer.max(sol, count_one(bits));
			return ;
		}
		//can progress! dfs
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m)
			{
//				System.out.println("moving to r, c : " + next_r + ", "+ next_c);
				dfs(next_r, next_c, (bits | (1 << map[cur_r][cur_c])));
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
		m = Integer.parseInt(st.nextToken());
		int bit = 0;
		map = new int [n][m];
		for (int i = 0; i < n; i++) {
			String str = br.readLine().toString();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str.charAt(j) - 'A';
//				System.out.print(map[i][j] + "\t");
			}
//			System.out.println("");
		}
		dfs(0, 0, 0);
		bw.write(sb.toString());
		bw.flush();
		System.out.println(sol);
		return ;
	}
}


