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
		Map<String, Integer> in = new HashMap<String, Integer>();
		n = Integer.parseInt(st.nextToken());
		int [] rank = new int[n];
		int sol = 0;
		for (int i = 0; i < n; i++) {
			String car = br.readLine();
			in.put(car, in.size());
			int carNum = in.get(car);
			rank[carNum] = i;
		}
		for (int i = 0; i < n; i++) {
			String car = br.readLine();
			int carNum = in.get(car);
			int carRank = rank[carNum];
			if (carRank > i){
				sol++;
				for (int j = 0; j < carNum; j++) {
					rank[j]++;
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


