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
		Map<Long, Long> info = new HashMap<>();
		for (int i = 0; i < n; i++) {
			Long temp_winner = -1L;
			st = new StringTokenizer(br.readLine()," ");
			Long sold_num = Long.parseLong(st.nextToken());
			info.clear();
			for (int sol_i = 0; sol_i < sold_num; sol_i++) {
				long sold = Long.parseLong(st.nextToken());
				//update info
				if (info.containsKey(sold)){
					info.put(sold, info.get(sold) + 1);
				}
				else{
					info.put(sold, 1L);
				}
				if (info.get(sold).compareTo(sold_num / 2) > 0)
					temp_winner = sold;
			}
			if (temp_winner != -1){
				System.out.println(temp_winner);
			}
			else{
				System.out.println("SYJKGW");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
