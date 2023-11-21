import java.util.*;
import java.io.*;

public class Main{
	//				  >   ^   <  v
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
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
		int level_num = -1;
		if (n % 2 == 0)
			level_num = (n / 2);
		else
			level_num = (n / 2) + 1;
		ArrayList<String> level[] = new ArrayList[level_num];
		for (int i = 0; i < level.length; i++) {
			level[i] = new ArrayList<>();
		}
		String[][] map = new String[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n ; j++){
				map[i][j] = st.nextToken();
			}
		}
		int cur_dir = 1;
		if (m < 0)
			cur_dir = 1;
		else
			cur_dir = -1;
		m = Math.abs(m);
		for (int i = 0; i < level_num; i++) {
			int start_r = 0 + i;
			int start_c = 0 + i;
			int end_r = n - 1 - i;
			int end_c = n - 1 - i;
			int cur_r = start_r;
			int cur_c = start_c;
			while (cur_c <= end_c){
				level[i].add(map[cur_r][cur_c]);
				cur_c++;
			}
			cur_c = end_c;
			cur_r = start_r + 1;
			while (cur_r <= end_r){
				level[i].add(map[cur_r][cur_c]);
				cur_r++;
			}
			cur_r = end_r;
			cur_c = end_c - 1;
			while (cur_c >= start_c){
				level[i].add(map[cur_r][cur_c]);
				cur_c--;
			}
			cur_c = start_c;
			cur_r = end_r - 1;
			while (cur_r > start_r){
				level[i].add(map[cur_r][cur_c]);
				cur_r--;
			}
//			System.out.println(level[i]);
		}
		ArrayList<Integer> level_head = new ArrayList<>();
		for (int i = 0; i < level_num; i++) {
			level_head.add(0);
		}
		for (int i = 0; i < level_num; i++) {
			int len = level[i].size();
			int cur_head = level_head.get(i);
			for (int j = 0; j < m; j++) {
				cur_head += cur_dir;
				if (cur_head >= len)
					cur_head = 0;
				else if (cur_head < 0)
					cur_head = len - 1;
//				System.out.println("level " + i + "'s head :  " + cur_head);
			}
			level_head.set(i, cur_head);
//			System.out.println("level " + i + "'s head :  " + level[i].get(cur_head));
			cur_dir *= -1;
		}
		for (int i = 0; i < level_num; i++) {
			int start_r = 0 + i;
			int start_c = 0 + i;
			int end_r = n - 1 - i;
			int end_c = n - 1 - i;
			int cur_r = start_r;
			int cur_c = start_c;
			int cur_head = level_head.get(i);
			int len = level[i].size();
			while (cur_c <= end_c){
				map[cur_r][cur_c] = level[i].get(cur_head);
				cur_c++;
				cur_head++;
				if (cur_head >= len)
					cur_head = 0;
			}
			cur_c = end_c;
			cur_r = start_r + 1;
			while (cur_r <= end_r){
				map[cur_r][cur_c] = level[i].get(cur_head);
				cur_head++;
				if (cur_head >= len)
					cur_head = 0;
				cur_r++;
			}
			cur_r = end_r;
			cur_c = end_c - 1;
			while (cur_c >= start_c){
				map[cur_r][cur_c] = level[i].get(cur_head);
				cur_head++;
				if (cur_head >= len)
					cur_head = 0;
				cur_c--;
			}
			cur_c = start_c;
			cur_r = end_r - 1;
			while (cur_r > start_r){
				map[cur_r][cur_c] = level[i].get(cur_head);
				cur_head++;
				if (cur_head >= len)
					cur_head = 0;
				cur_r--;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++){
				sb.append(map[i][j]);
				if (j != n - 1)
					sb.append(" ");
			}
			if (i != n - 1)
				sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


