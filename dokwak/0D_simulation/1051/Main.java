import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		String[] map = new String[n];
		for (int i = 0; i < n; i++) {
			map[i] = br.readLine();
		}
		int sol = 0;
		for (int len = 1; len <= Integer.min(n, m); len++) {
			for (int i = 0; i + len - 1 < n; i++) {
				for (int j = 0; j + len - 1 < m ; j++){
					int r_start = i;
					int c_start = j;
					int r_end = i + len - 1;
					int c_end = j + len - 1;
					if (map[r_start].charAt(c_start) == map[r_start].charAt(c_end) &&
							map[r_start].charAt(c_start) == map[r_end].charAt(c_start) &&
							map[r_start].charAt(c_start) == map[r_end].charAt(c_end)){
						sol = len;
						break;
					}
				}
			}
		}
		System.out.println(sol * sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


