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
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			ArrayList<Integer> arr = new ArrayList<>();
			//init arr
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < n; i++) {
				arr.add(Integer.parseInt(st.nextToken()));
			}
			//cmd
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine()," ");
				String cmd = st.nextToken();
				if (cmd.compareTo("I") == 0){
					int start_index = Integer.parseInt(st.nextToken());
					int entry = Integer.parseInt(st.nextToken());
					arr.add(start_index, entry);
				}
				else if (cmd.compareTo("D") == 0){
					int start_index = Integer.parseInt(st.nextToken());
					arr.remove(start_index);
				}
				else if (cmd.compareTo("C") == 0){
					int start_index = Integer.parseInt(st.nextToken());
					int entry = Integer.parseInt(st.nextToken());
					arr.set(start_index, entry);
				}
			}
			//print
			sb.append("#" + (t_i + 1) + " ");
			if (l > arr.size() - 1)
				sb.append("-1");
			else
				sb.append(arr.get(l));
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


