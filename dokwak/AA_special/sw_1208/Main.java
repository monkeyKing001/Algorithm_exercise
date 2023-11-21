import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		PriorityQueue<int[]> pq_des = new PriorityQueue<int[]>(new Comparator<int[]>(){
			@Override
			public int compare(int [] block1, int[] block2){
				return (Integer.compare(block2[1], block1[1]));
			}
		});
		PriorityQueue<int[]> pq_asc = new PriorityQueue<int[]>(new Comparator<int[]>(){
			@Override
			public int compare(int [] block1, int[] block2){
				return (Integer.compare(block1[1], block2[1]));
			}
		});
		//input
		int T = 10;
		for (int t_i = 0; t_i < T; t_i++) {
			pq_asc.clear();
			pq_des.clear();
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 0; i < 100; i++) {
				m = Integer.parseInt(st.nextToken());
				int [] entry = new int[2];
				entry[0] = i;
				entry[1] = m;
				pq_asc.add(entry);
				pq_des.add(entry);
			}
//			System.out.println("sm, big : " +pq_asc.peek()[1]+", "+pq_des.peek()[1]);
			for (int i = 0; i < n; i++) {
				int[] biggest = pq_des.poll();
				int[] smallest = pq_asc.poll();
				biggest[1]--;
				smallest[1]++;
				pq_des.add(biggest);
				pq_asc.add(smallest);
			}
			System.out.println("#" + (t_i + 1) + " " + (pq_des.peek()[1] - pq_asc.peek()[1]));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


