import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static long sol_sum = Long.MAX_VALUE;
	static int sol_l_i, sol_r_i, sol_mid_i;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		arr.sort(Comparator.naturalOrder());
		for (int l_i = 0; l_i < n - 2; l_i++) {
			//twoPointer start
			int mid_i = l_i + 1;
			int r_i = arr.size() - 1;
			while (mid_i < r_i){
				long cur_sum = (long)arr.get(l_i) + (long)arr.get(mid_i) + (long)arr.get(r_i); 
				long abs_cur_sum = Math.abs(cur_sum);
				if (abs_cur_sum < sol_sum){
					sol_l_i = l_i;
					sol_r_i = r_i;
					sol_mid_i = mid_i;
					sol_sum  = abs_cur_sum;
				}
				if (cur_sum < 0)
					mid_i++;
				else if (cur_sum > 0)
					r_i--;
				else
					break;
			}
		}
		System.out.println(arr.get(sol_l_i)+" "+arr.get(sol_mid_i)+" "+arr.get(sol_r_i));
		return ;
	}
}
