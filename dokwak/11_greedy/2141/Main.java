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
		long totalPeople = 0;
		PriorityQueue<long[]> pq = new PriorityQueue<>(new Comparator<long[]>(){
			@Override
			public int compare(long [] e1, long [] e2){
				return (Long.compare(e1[0], e2[0]));
			}
		});
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			long pos = Long.parseLong(st.nextToken());
			long people = Long.parseLong(st.nextToken());
			long [] info = new long[2];
			info[0] = pos;
			info[1] = people;
			pq.add(info);
			totalPeople += people;
		}
		long[] startPoint = pq.poll();
		long farAway = startPoint[1];
		long comeCloser = totalPeople - farAway;
		long position = startPoint[0];
//		System.out.println(startCost);
		while (pq.size() != 0 && farAway < comeCloser){
			long [] nextPoint = pq.poll();
			farAway += nextPoint[1];
			comeCloser -= nextPoint[1];
			position = nextPoint[0];
			if (farAway >= comeCloser)
				break;
		}
		System.out.println(position);
//		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
