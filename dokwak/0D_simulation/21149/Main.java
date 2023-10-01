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
		Map<Integer, Integer> time_stamp = new TreeMap<>();
		long total_msg = 0;
		for (int i = 1; i < m + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			total_msg += n;
			int sender = Integer.parseInt(st.nextToken());
			if(time_stamp.containsKey(sender)){
				total_msg -= i - time_stamp.get(sender);
				time_stamp.put(sender, i);
			}
			else{
				total_msg -= i;
				time_stamp.put(sender, i);
			}
			System.out.println(total_msg);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


