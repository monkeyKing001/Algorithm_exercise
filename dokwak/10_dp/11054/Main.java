import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> inc = new ArrayList<>();
	static ArrayList<Integer> dec = new ArrayList<>();
	public static int find_min_bigger_dec(int num){
		int idx = -1;
		int l = 0;
		int r = dec.size() - 1;
		int mid = (l + r) / 2;
		while (l <= r){
			mid = (l + r) / 2;
			//got idx candidate. more challenge
			if (dec.get(mid) >= num){
				idx = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		return (idx);
	}
	public static int find_min_biiger(int num){
		int idx = -1;
		int l = 0;
		int r = inc.size() - 1;
		int mid = (l + r) / 2;
		while (l <= r){
			mid = (l + r) / 2;
			//got idx candidate. more challenge
			if (inc.get(mid) >= num){
				idx = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		return (idx);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int inc_dp[] = new int[n];
		int dec_dp[] = new int[n];
		int arr[] = new int [n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		//make increase seq;
		for (int i = 0; i < n; i++) {
			int num = arr[i];
			if (inc.size() == 0 || inc.get(inc.size() - 1) < num)
			{
				inc.add(num);
				inc_dp[i] = inc.size();
			}
			else{
				int insert_idx = find_min_biiger(num);
				inc.set(insert_idx, num);
				inc_dp[i] = insert_idx + 1;
			}
		}
//		for (int i = 0; i < n; i++) {
//			System.out.print(inc_dp[i] + " ");
//		}
//		System.out.println();
		int sol = 0;
		for (int i = n - 1; i > -1; i--) {
			int num = arr[i];
			if (dec.size() == 0 || dec.get(dec.size() - 1) < num)
			{
				dec.add(num);
				dec_dp[i] = dec.size();
			}
			else{
				int insert_idx = find_min_bigger_dec(num);
				dec.set(insert_idx, num);
				dec_dp[i] = insert_idx + 1;
			}
			sol = Integer.max(sol, inc_dp[i] + dec_dp[i] - 1);
		}
//		for (int i = 0; i < n; i++) {
//			System.out.print(dec_dp[i] + " ");
//		}
//		System.out.println();
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


