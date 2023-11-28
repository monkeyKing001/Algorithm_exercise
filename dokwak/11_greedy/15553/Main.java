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
		int totalTime = 0;
		ArrayList<Integer> f = new ArrayList<>();
		int start = Integer.MAX_VALUE;
		int end = -1;
		int prvTime = 0;
		ArrayList<int[]> timeGap = new ArrayList<>();
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			if (i == 0)
				start = num;
			else{
				pq.add(num - prvTime - 1);
			}
			prvTime = num;
			if (i == n - 1){
				end = num;
			}
		}
		totalTime = end - start + 1;
		while(m > 1 && pq.size() != 0){
			totalTime -= pq.poll();
			m--;
		}
		System.out.println(totalTime);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


