import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static long[][] dp;
	static long[] arr;
	public static int bst (int l, int r, long temp_sum){
		int sol = -1;
		int mid = (l + r) / 2;
		long cur_sum = 4000000000l;
		while (l <= r){
			//take a shot for bigger mid
			if (arr[mid] + temp_sum < 0){
				l = mid + 1;
			}
			//take a shot for smaller mid
			else if (arr[mid] + temp_sum > 0){
				r = mid - 1;
			}
			else if (arr[mid] + temp_sum == 0)
			{
				sol = mid;
				break;
			}
			if (Math.abs(arr[mid] + temp_sum) < Math.abs(cur_sum))
			{
				sol = mid;
				cur_sum = arr[mid] + temp_sum;
			}
			mid = (l + r) / 2;
		}
		return (sol);
	}
	
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		arr = new long[n];
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr[i] = (long)Integer.parseInt(st.nextToken());
		}
		dp = new long[n][n];
		Arrays.sort(arr);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				dp[i][j] = arr[i] + arr[j];	
			}
		}
		int []sol = {0, 1, 2};
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 2; j < n; j++) {
//				System.out.println("cur num : " + arr[i]+ ", "+ arr[j]);
				long temp_sum = dp[i][j];
				int temp_idx = bst(i + 1, j - 1, temp_sum);
//				System.out.println("target is " + target);
//				left?
				if (Long.compare(Math.abs(arr[sol[0]] + arr[sol[1]] + arr[sol[2]]) , Math.abs(temp_sum + arr[temp_idx])) > 0)
				{
//					System.out.println("found min abs : " + arr[i] + ", " + arr[temp_idx]+ ", "+arr[j]);
					sol[0] = i; sol[1] = temp_idx; sol[2] = j;
				}
			}
		}
		System.out.print(arr[sol[0]] + " ");
		System.out.print(arr[sol[1]] + " ");
		System.out.print(arr[sol[2]]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
