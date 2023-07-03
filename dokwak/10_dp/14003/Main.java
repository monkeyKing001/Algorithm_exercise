import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> arr_sol = new ArrayList<>();
	public static int lw_bound_idx(int target)
	{
		int l = 0, r = arr_sol.size() - 1;
		int mid = (l + r) / 2;
		int sol = -1;
		while (l <= r)
		{
			if (arr_sol.get(mid) < target)
				l = mid + 1;
			else if(arr_sol.get(mid) >= target){
				sol = mid;
				r = mid - 1;
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
		int []arr = new int[1000001];
		int []dp = new int[1000001];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
//		System.out.println("arr");
//		for (int i = 0; i < n; i++) {
//			System.out.print(arr[i] + " ");	
//		}
//		System.out.println();
		int max_i = -1;
		for (int i = 0; i < n; i++) {
			int num = arr[i];
//			System.out.println("num : " + num);
			if (arr_sol.size() == 0 || num > arr_sol.get(arr_sol.size() - 1))
			{
				arr_sol.add(num);
				max_i = i;
				dp[i] = arr_sol.size() - 1;
//				System.out.println("new biggest : " + num);
			}
			else{
				int idx = lw_bound_idx(num);
				if (idx == arr_sol.size() - 1)
					max_i = i;
				arr_sol.set(idx, num);
				dp[i] = idx;
				//max i?
			}
		}
		ArrayList<Integer> temp = new ArrayList<>();
		int cnt = arr_sol.size();
		int cur_i = max_i;
		System.out.println(cnt);
		while (cur_i > -1)
		{
			if (dp[cur_i] == cnt - 1)
			{
//				System.out.println("adding arr[" + cur_i + "] : " + arr[cur_i]);
				temp.add(arr[cur_i]);
				cnt--;
			}
			cur_i--;
		}
		for (int i = temp.size() - 1; i > - 1; i--) {
			sb.append(Integer.toString(temp.get(i)) + " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
