import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {1, 0, -1, 0}; // + => left, - => right
	static int dc[] = {0, 1, 0, -1};//  left => +, right => -
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int cur_r = 0;
		int cur_c = 0;
		int left_bound = 0;
		int upper_bound = 0;
		int right_bound = 0;
		int lower_bound = 0;
		int d = 0;
		ArrayList<int[]> stepped = new ArrayList<>();
		int startPoint[] = new int[2];
		startPoint[0] = 0;
		startPoint[1] = 0;
		stepped.add(startPoint);
		n = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		for (int i = 0; i < n; i++) {
			char cmd = str.charAt(i);
			if (cmd == 'R'){
				d--;
				if (d < 0)
					d = 3;
			}
			else if (cmd == 'L'){
				d++;
				d %= 4;
			}
			else if (cmd == 'F'){
				cur_r += dr[d];
				cur_c += dc[d];
				int curStepped[] = new int[2];
				curStepped[0] = cur_r;
				curStepped[1] = cur_c;
//				System.out.println(Arrays.toString(curStepped));
				stepped.add(curStepped);
				upper_bound = Integer.min(upper_bound, cur_r);
				left_bound = Integer.min(left_bound, cur_c);
				lower_bound = Integer.max(lower_bound, cur_r);
				right_bound = Integer.max(right_bound, cur_c);
			}
		}
		int h  = lower_bound - upper_bound + 1;
		int w = right_bound - left_bound + 1;
		int map[][] = new int[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w ; j++){
				map[i][j] = '#';
			}
		}
		for (int i = 0; i < stepped.size(); i++) {
			stepped.get(i)[0] += (upper_bound * -1);
			stepped.get(i)[1] += (left_bound * -1);
			int stepped_r = stepped.get(i)[0];
			int stepped_c = stepped.get(i)[1];
			map[stepped_r][stepped_c] = '.';
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w ; j++){
				System.out.print((char)map[i][j]);
			}
			System.out.println();
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
