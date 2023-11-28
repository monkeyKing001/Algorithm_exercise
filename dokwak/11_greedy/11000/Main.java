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
		ArrayList<int[]> all_info = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int info[] = new int[2];
			info[0] = start;
			info[1] = end;
			all_info.add(info);
		}
		all_info.sort(new Comparator<int[]>(){
					@Override
					public int compare(int[] e1, int []e2)
					{
						if (e1[0] == e2[0])
							return (Integer.compare(e1[1], e2[1]));
						return (Integer.compare(e1[0], e2[0]));
					}
				});
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i = 0; i < all_info.size(); i++) {
			int info[] = all_info.get(i);
			int start = info[0];
			int end = info[1];
			if (pq.size() == 0 || pq.peek() > start){
				pq.add(end);
			}
			else{
				pq.poll();
				pq.add(end);
			}

		}
		System.out.println(pq.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


