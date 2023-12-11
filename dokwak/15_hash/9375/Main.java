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
			Map<String, Integer> map = new HashMap<String, Integer>();
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine()," ");
				String name = st.nextToken();
				String kind = st.nextToken();
				map.put(kind, map.getOrDefault(kind, 1) + 1);
			}
			int total = 1;
			for (String kind : map.keySet()){
				total *= map.get(kind);
			}
			total--;
			sb.append(total);
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


