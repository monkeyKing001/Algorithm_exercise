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
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		n = Integer.parseInt(st.nextToken());
		long sol = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			pq.add(num);
		}
		while (pq.size() != 1){
			int num = pq.poll();
//			System.out.println("num : " + num);
			if (pq.size() >= 1){
				int add = pq.poll();
				num += add;
//				System.out.println("adding : " + add);
			}
			sol += num;
			pq.add(num);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


