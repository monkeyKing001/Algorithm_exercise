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
		HashMap<String, String> map= new HashMap<>();

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			String site;
			String pw;
			site = st.nextToken();
			pw = st.nextToken();
			map.put(site, pw);
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			String site;
			site = st.nextToken();
			sb.append(map.get(site) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
