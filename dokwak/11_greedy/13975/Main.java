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
		PriorityQueue<Long> pq = new PriorityQueue<>();
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine()," ");
			pq.clear();
			for (int i = 0; i < m; i++) {
				long num = Long.parseLong(st.nextToken());
				pq.add(num);
			}
			long totalCal  = 0;
			while (pq.size() != 1){
				long top = (long)pq.poll();
				if (pq.size() != 0){
					top += pq.poll();
					totalCal += top;
				}
				pq.add(top);
			}
			sb.append(totalCal +"\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


