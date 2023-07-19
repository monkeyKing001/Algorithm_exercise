import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st;
		

		//input
		for (int t_i = 0; t_i < 10; t_i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			ArrayList<Integer> arr = new ArrayList<>();
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				arr.add(Integer.parseInt(st.nextToken()));
			}
			st = new StringTokenizer(br.readLine(), " ");
			int cmd_num = Integer.parseInt(st.nextToken());
//			System.out.println("cmd_num : " + cmd_num);
			String cmd = br.readLine();
			st = new StringTokenizer(cmd, " ");
			while (st.hasMoreTokens()){
				String cmd_ = st.nextToken();
				if (cmd_.compareTo("D") == 0)
				{
					int start_index = Integer.parseInt(st.nextToken());
					int entry_num = Integer.parseInt(st.nextToken());
					for (int i = 0; i < entry_num; i++) {
						arr.remove(start_index);
					}
				}
				else if (cmd_.compareTo("I") == 0)
				{
					int start_index = Integer.parseInt(st.nextToken());
					int entry_num = Integer.parseInt(st.nextToken());
					ArrayList<Integer> add_arr = new ArrayList<>();
					for (int i = 0; i < entry_num; i++) {
						int entry = Integer.parseInt(st.nextToken());
						add_arr.add(entry);
					}
					arr.addAll(start_index, add_arr);
				}
				else if (cmd_.compareTo("A") == 0)
				{
					int entry_num = Integer.parseInt(st.nextToken());
					ArrayList<Integer> add_arr = new ArrayList<>();
					for (int i = 0; i < entry_num; i++) {
						int entry = Integer.parseInt(st.nextToken());
						add_arr.add(entry);
					}
					arr.addAll(add_arr);
				}
			}
			//print sol
			sb.append("#" + (t_i + 1) + " ");
			for (int i = 0; i < 10; i++) {
				sb.append(arr.get(i) + " ");
			}
			sb.append("\n");
		}
		System.out.print(sb.toString());
		return ;
	}
}


