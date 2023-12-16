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
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		int prv = 0;
		int totalDiff = 0;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			if (i != 0)
				totalDiff += num - prv;
			pq.add(num - prv);
			prv = num;
		}
		while (--m > 0){
			int sub = pq.poll();
//			sb.append("sub : "  + sub);
//			sb.append("\n");
			totalDiff -= sub;
		}
		sb.append(totalDiff);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


