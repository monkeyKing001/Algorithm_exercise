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
		ArrayList<int[]> arr[] = new ArrayList[n + 1];
		int [] w = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			arr[i] = new ArrayList<>();
		}
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 1; i < n + 1; i++) {
			w[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			if (w[u] >= w[v]){
				int info1[] = new int [2];
				info1[0] = u;
				info1[1] = v;
				arr[v].add(info1);
			}
			if (w[v] >= w[u]){
				int info2[] = new int [2];
				info2[0] = u;
				info2[1] = v;
				arr[u].add(info2);
			}

		}
		int sol = 0;
		for (int i = 1; i < n + 1; i++) {
			if (arr[i].size() == 0)
			{
				sol++;
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


