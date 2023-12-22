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
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		ArrayList<Integer> works[] = new ArrayList[1001];
		for (int i = 0; i < 1001; i++) {
			works[i] = new ArrayList<>();
		}
		int lastDay = -1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int costDay = Integer.parseInt(st.nextToken());;
			int score = Integer.parseInt(st.nextToken());;
			lastDay = Integer.max(lastDay, costDay);
			works[costDay].add(score);
		}
		int totalScore = 0;
		int [] sol = new int[1001];
		for (int day = lastDay; day > 0; day--) {
			while (works[day].size() != 0){
				int score = works[day].remove(0);
				pq.add(score);
			}
			if (pq.size() != 0){
				sol[day] = pq.poll();
				totalScore += sol[day];
//				System.out.println("in day " + day + " best score is " + sol[day]);
			}
		}
		System.out.println(totalScore);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
