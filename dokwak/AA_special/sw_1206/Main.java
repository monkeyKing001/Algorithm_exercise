import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		int T = 10;
		for (int t_i = 0; t_i < T; t_i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			int building[] = new int[n];//건물 높이 입력.
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < n; i++) {
				building[i] = Integer.parseInt(st.nextToken());
			}
			//building = {0, 0, 34, 35, 258, 58, 543 0, 0};
			int sol = 0;
			for (int i = 2; i < n - 2; i++) {
				int cur_h = building[i];
				int left_max = Integer.max(building[i - 1], building[i - 2]);
				int right_max = Integer.max(building[i + 1], building[i + 2]);
				if (cur_h > left_max && cur_h > right_max){
					sol += Integer.min(cur_h - left_max, cur_h - right_max);
				}
			}
			System.out.println("#" + (t_i + 1) + " " + sol);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


