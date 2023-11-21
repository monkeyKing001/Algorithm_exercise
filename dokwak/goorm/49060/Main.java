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
		ArrayList<Integer> arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		arr.sort(Comparator.naturalOrder());
		int sol = Integer.MAX_VALUE;
		int l = 0;
		int r = 0; 
		while (l <= r && r < n){
			if (arr.get(r) - arr.get(l) <= m){
				sol = Integer.min(sol, n - (r - l + 1));
				r++;
			}
			else
				l++;
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
