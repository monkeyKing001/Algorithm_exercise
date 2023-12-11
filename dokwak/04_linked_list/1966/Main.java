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
		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			int target = m;
			ArrayList<int[]> arr = new ArrayList<>();
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < n; i++) {
				int [] info = new int[2];
				info[0] = i;
				info[1] = Integer.parseInt(st.nextToken());
				arr.add(info);
			}
			int count = 0;
			while (arr.size() != 0){
				int cur_idx = arr.get(0)[0];
				int cur_pri = arr.get(0)[1];
				boolean print = true;
				for (int i = 1; i < arr.size(); i++) {
					if (arr.get(i)[1] > cur_pri){
						print = false;
					}
				}
				int [] task = arr.remove(0);
				count++;
				if (!print){
					arr.add(task);
					count--;
				}
				if (print && cur_idx == target)
					break;
			}
			sb.append(count + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


