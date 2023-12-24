import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int limit;
	public static int bstLowerBound(ArrayList<Integer>arr, int key){
		int idx = -1;
		int left = 0;
		int right = limit - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (arr.get(mid) < key) {
				right = mid - 1;
			}
			else{
				idx = mid;
				left = mid + 1;
			}
		}
		return idx;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int hole [] = new int [n + 2];
		Integer dp [] = new Integer [n + 2];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			hole[i + 1] = Integer.parseInt(st.nextToken());
		}
		dp[0] = Integer.MAX_VALUE;
		for (int i = 1; i < n + 1; i++) {
			int holeSize = hole[i];
			dp[i] = Integer.min(holeSize, dp[i -1]);
		}
		dp[n + 1] = 0;
		limit = n + 1;
		st = new StringTokenizer(br.readLine()," ");
		ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(dp));
//		System.out.println(arr.toString());
		for (int i = 0; i < m; i++) {
			int pizzaSize = Integer.parseInt(st.nextToken());
			int idx = bstLowerBound(arr, pizzaSize);
//			System.out.println(pizzaSize+ " stacking in " + idx);
			if (idx == -1 || idx == 0){
				limit = 0;
				break;
			}
			limit = idx;
		}
		System.out.println(limit);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


