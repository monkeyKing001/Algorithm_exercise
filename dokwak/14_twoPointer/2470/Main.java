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
		ArrayList<Integer> arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		arr.sort(Comparator.naturalOrder());
//		for (int i = 0; i < n; i++) {
//			System.out.print(arr.get(i) + " ");
//		}
		int l_i = 0;
		int r_i = arr.size() - 1;
		int sol_l_i = 0;
		int sol_r_i = arr.size() - 1;
		int temp_sum = Integer.MAX_VALUE;
		while (l_i < r_i){
			int cur_sum = arr.get(l_i) + arr.get(r_i);
//			System.out.println("l, r : " + l_i+", "+ r_i );
			if (cur_sum == 0){
				sol_l_i = l_i;
				sol_r_i = r_i;
				temp_sum = 0;
				break;
			}
			if (Math.abs(cur_sum) < temp_sum){
//				System.out.println("found min sum l, r : " + l_i+", "+ r_i );
//				System.out.println("sum : " + cur_sum);
				temp_sum = Math.abs(cur_sum);
				sol_l_i = l_i;
				sol_r_i = r_i;
			}
			if (cur_sum < 0) l_i++;
			else r_i--;
		}
		System.out.println(arr.get(sol_l_i) + " " +  arr.get(sol_r_i));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


