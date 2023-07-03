import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int [][] dp = new int [41][41];
	static long sol = 0;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		TreeMap<Integer, Integer> map = new TreeMap<>();
		int [] arr = new int [n + 1];
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr[i] =  Integer.parseInt(st.nextToken());
		}
		int mid = n / 2;
		int []left = new int[mid + 1];
		int []right = new int[n - mid - 1];
		for (int i = 0; i < mid + 1; i++) {
			left[i] = arr[i];
		}
		for (int i = mid + 1; i < n; i++) {
			right[i - (mid + 1)] = arr[i];
		}
		//left subsum
//		System.out.println("left");
//		for (int i = 0; i < left.length; i++) {
//			System.out.print(left[i] + " ");
//		}
		for (int i = 0; i < (1 << left.length); i++) {
			int temp_sum = 0;
			for (int j = 0; j < left.length; j++) {
				if (((1 << j) & i) != 0){//hit
					temp_sum += left[j];
				}
			}
			if (map.containsKey(temp_sum) == true){
				int temp_cnt = map.get(temp_sum);
				map.put(temp_sum, temp_cnt + 1);
			}
			else{
				map.put(temp_sum, 1);
			}
		}
//		System.out.println();
		//right subsum
//		System.out.println("right");
//		for (int i = 0; i < right.length; i++) {
//			System.out.print(right[i] + " ");
//		}
//		System.out.println();
		for (int i = 0; i < (1 << right.length); i++) {
			int temp_sum = 0;
			for (int j = 0; j < right.length; j++) {
				if (((1 << j) & i) != 0){
					temp_sum += right[j];
				}
			}
			if (map.containsKey(m - temp_sum) == true)
			{
//				System.out.println("temp_right sum : " + temp_sum);
//				System.out.println("left has subset : " + (m - temp_sum));
				sol += map.get(m - temp_sum);
			}
		}
//		System.out.println();
//		System.out.print("sol : ");
		if (m == 0)
			sol--;
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
