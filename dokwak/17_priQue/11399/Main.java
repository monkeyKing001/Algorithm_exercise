import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			int time = Integer.parseInt(st.nextToken());
			pq.add(time);
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			int wait_time = pq.size() * pq.poll();
			sol += wait_time;
		}
		System.out.println(sol);
		return ;
	}
}
