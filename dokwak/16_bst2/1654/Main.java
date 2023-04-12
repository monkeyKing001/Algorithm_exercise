import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		Long m = Long.parseLong(st.nextToken());

		Long []lines = new Long[n];
		Long max_len = 0L;
		for (int i = 0; i < n; i++) {
			Long line_len = Long.parseLong(br.readLine());
			lines[i] = line_len;
			if (line_len > max_len)
				max_len = line_len;
		}
		Long min_len = 1L;
		Long mid_len = min_len + (max_len - min_len) / 2;
		Long sol = mid_len;
		while (min_len <= max_len)
		{
			Long cutting_num = 0L;
			for (int i = 0; i < n; i++) {
				cutting_num += lines[i] / mid_len; 
			}
			//success case
			if (cutting_num >= m)
			{
//				System.out.println("success with mid_len, cutting_num :  " + mid_len + ", " + cutting_num);
				sol = mid_len;
				min_len = mid_len + 1;
			}
			//fail case
			else
				max_len = mid_len - 1;
			mid_len = min_len + (max_len - min_len) / 2;
		}
		//input
		//n = Integer.parseInt(st.nextToken());
		System.out.println(sol);
		return ;
	}
}
