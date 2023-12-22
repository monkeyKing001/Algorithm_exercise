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
		ArrayList<Integer> arr[] = new ArrayList[10001];
		for (int i = 0; i < 10001; i++) {
			arr[i] = new ArrayList<>();
		}
		int sol = 0;
		int lastDay = -1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int pay = Integer.parseInt(st.nextToken());
			int day = Integer.parseInt(st.nextToken());
			arr[day].add(pay);
			lastDay = Integer.max(lastDay, day);
		}
		PriorityQueue<Integer>pq = new PriorityQueue<>(Comparator.reverseOrder());
		for (int i = lastDay; i > 0; i--) {
			while (arr[i].size() != 0){
				pq.add(arr[i].remove(0));
			}
			if (pq.size() != 0)
				sol+=pq.poll();
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


