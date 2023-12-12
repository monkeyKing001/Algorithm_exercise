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
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] e1, int [] e2){
				return (Integer.compare(e1[0], e2[0]));
			}
		});
		n = Integer.parseInt(st.nextToken());
		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int [] info = new int[2];
				info[0] = a;
				info[1] = b;
				pq.add(info);
			}
			int lastB = n + 1;
			int count = 0;
			while (pq.size() != 0){
				int rank[] = pq.poll();
				if (rank[1] < lastB){
					lastB = rank[1];
					count++;
				}
			}
			sb.append(count);
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


