import java.io.FileInputStream;
import java.util.Iterator;
import java.util.*;
import java.io.*;

class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
			long sol = 0;
			int [] r_dp = new int [n + 1];
			int [] c_dp = new int [m + 1];
			//init
			for (int i = 0; i < n + 1; i++) {
				r_dp[i] = 0;
			}
			for (int i = 0; i < m + 1; i++) {
				c_dp[i] = 0;
			}
			TreeSet<Integer> safe_set = new TreeSet<>();
			//map 0 step;
			for (int i = 1; i < n + 1; i++) {
				int temp_r_max = r_dp[i];
				int temp_c_max = -1;
				for (int j = 1; j < m + 1; j++) {
					int num = sc.nextInt();
					System.out.println("chenking num : " + num);
					temp_c_max = c_dp[j];
					if (num > temp_c_max && num > temp_r_max){
						safe_set.add(num);
						System.out.println("adding " + num);
						if (safe_set.contains(temp_r_max) == true)
						{
							System.out.println("not safe r " + temp_r_max);
							safe_set.remove(temp_r_max);
						}
						if (safe_set.contains(c_dp[j]) == true)
						{
							safe_set.remove(c_dp[j]);
							System.out.println("not safe c " + c_dp[j]);
						}
						temp_r_max = num;
						c_dp[j] = num;
					}
					if (c_dp[j] < num)
					{
						if (safe_set.contains(temp_c_max) == true)
						{
							safe_set.remove(temp_c_max);
							System.out.println("not safe temp_c " + temp_c_max);
						}
						c_dp[j] = num;
					}
					if (temp_r_max < num)
					{
						if (safe_set.contains(temp_r_max) == true)
						{
							safe_set.remove(temp_r_max);
							System.out.println("not safe temp_r " + temp_r_max);
						}
						temp_r_max = num;
					}
				}
				r_dp[i] = temp_r_max;
			}
			//q step
			System.out.println("init safe num : " + safe_set.size());
			
			for (int i = 0; i < q; i++) {
				int r = sc.nextInt(), c = sc.nextInt(), x = sc.nextInt();
				int r_max = r_dp[r];
				int c_max = c_dp[c];
				System.out.println("biggest in row, num : " + r +", "+ r_max);
				System.out.println("biggest in col, num : " + c +", "+ c_max);
				if (r_max < x){
					if (safe_set.contains(r_max))
					{
						safe_set.remove(r_max);
						System.out.println("removing : "+ r_max);
					}
					r_dp[r] = x;
				}
				if (c_max < x){
					if (safe_set.contains(c_max))
					{
						safe_set.remove(c_max);
						System.out.println("removing : "+ c_max);
					}
					c_dp[c] = x;
				}
				if (c_max < x  && r_max < x){
					System.out.println("new num : " + x);
					c_dp[c] = x;
					r_dp[r] = x;
					safe_set.add(x);
				}
				sol += safe_set.size();
			}
			System.out.println("#"+ Integer.toString(test_case) + " " + sol);
		}
		sc.close();
	}
}
