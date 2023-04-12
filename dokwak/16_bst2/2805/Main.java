import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int []trees = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int len = Integer.parseInt(st.nextToken());
			trees[i] = len;
		}
		long max_h = Arrays.stream(trees).max().getAsInt();	
		long min_h = 0L;
		long mid_h = min_h + ((max_h - min_h) / 2);
		long sol = 0;
		while (min_h <= max_h)
		{
			long taking = 0;
			mid_h = min_h + ((max_h - min_h) / 2);
			for (int i = 0; i < n; i++) {
				if (trees[i] - mid_h < 0)
					taking += 0;
				else
					taking += trees[i] - mid_h;
			}
			if (taking >= m)//success
			{
				min_h = mid_h + 1;
				sol = mid_h;
			}
			else//fail;
				max_h = mid_h - 1;
		}
		System.out.println(sol);
		return ;
	}
}

