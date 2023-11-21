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
		ArrayList<Integer> arr = new ArrayList<>();
		//PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			pq.add(num);
		}
		int sol = 0;
		while (pq.size() != 1){
			int a = pq.poll();
			int b = pq.poll();
			sol += a + b;
			pq.add(a + b);
			//System.out.println(a);
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


