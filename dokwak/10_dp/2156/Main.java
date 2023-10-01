import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int arr [] = new int [n + 1];
		int max [] = new int[n + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			arr[i] = Integer.parseInt(st.nextToken());
		}
		max[0] = arr[0];
		if (n == 1)
		{
			System.out.println(max[0]);
			return;
		}
		max[1] = max[0] + arr[1];
		if (n == 2)
		{
			System.out.println(max[1]);
			return;
		}
		int i_two_max = -1;
		i_two_max = Integer.max(max[0] + arr[2], i_two_max);
		i_two_max = Integer.max(arr[1] + arr[2], i_two_max);
		i_two_max = Integer.max(arr[0] + arr[1], i_two_max);
		max[2] = i_two_max;
		if (n == 3)
		{
			System.out.println(max[2]);
			return;
		}
		int i_thr_max = -1;
		i_thr_max = Integer.max(0 + arr[1] + arr[2], i_thr_max); 
		i_thr_max = Integer.max(max[1] + arr[3], i_thr_max); 
		i_thr_max = Integer.max(max[0] + arr[2] + arr[3], i_thr_max); 
		max[3] = i_thr_max;
		if (n == 4)
		{
			System.out.println(max[3]);
			return;
		}
		for (int i = 4; i < n; i++) {
			int temp_max = -1;
			//case1.
			temp_max = Integer.max(max[i - 4] + arr[i - 1] + arr[i - 2], temp_max);//not drink this time, because having drink straight two in a row last time. 
			//case2.
			temp_max = Integer.max(max[i - 2] + arr[i], temp_max);//drink this time, because not having drink last time. 
			//case3.
			temp_max = Integer.max(max[i - 3] + arr[i - 1] + arr[i], temp_max);//drink this time, because this time is the second straight drinking.
			max[i] = temp_max;
		}
//		for (int i = 0; i < n; i++) {
//			System.out.print(max[i] + " ");
//		}
//		System.out.println();
		System.out.println(max[n - 1]);
		return ;
	}
}


