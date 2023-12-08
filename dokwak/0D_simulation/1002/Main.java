import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {1, 1, -1, -1}; 
	static int dc[] = {1, -1, 1, -1}; 
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
			Set<String> set = new HashSet<String>();
			int colA = Integer.parseInt(st.nextToken());
			int rowA = Integer.parseInt(st.nextToken());
			int disA = Integer.parseInt(st.nextToken());
			int colB = Integer.parseInt(st.nextToken());
			int rowB = Integer.parseInt(st.nextToken());
			int disB = Integer.parseInt(st.nextToken());
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


