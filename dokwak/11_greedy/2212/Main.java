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
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		int arr[] = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr[i] =  Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		for (int i = 0; i < n - 1; i++) {
			int dis = arr[i + 1] - arr[i];
			pq.add(dis);
		}
		int sol = arr[n - 1] - arr[0];
		while (pq.size() != 0 && --m > 0)
			sol -= pq.poll();
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


