import java.util.*;
import java.io.*;

public class Main{
	static int n;
	static int m;
	static ArrayList<Integer> arr;
	static int []prev_buf = new int[10];
	static void rec(int cur_i, int []buf, int[] check_buf)
	{
		if (cur_i == m)
		{
			boolean dup = true;
			for (int i = 0; i < m; i++) {
				if (prev_buf[i] != buf[i])
					dup = false;
			}
			if (dup == true)
				return ;
			for (int i = 0; i < m; i++) {
				System.out.print(buf[i] + " ");
				prev_buf[i] = buf[i];
			}
			System.out.print("\n");
		}
		else
		{
			int prev = -1;
			for (int i = 0; i < n; i++) {
				if (check_buf[i] == 0 && arr.get(i) != prev)
				{
					buf[cur_i] = arr.get(i);
					check_buf[i] = 1;
					rec(cur_i + 1, buf, check_buf);
					check_buf[i] = 0;
					prev = arr.get(i);
				}
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		int []buf = new int[m];
		int []check_buf = new int[n];
		for (int i = 0; i < n; i++) {
			check_buf[i] = 0;
		}
		arr.sort(Comparator.naturalOrder());
		//input
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (prev != arr.get(i))
			{
				buf[0] = arr.get(i);
				check_buf[i] = 1;
				rec(0 + 1, buf, check_buf);
				check_buf[i] = 0;
				prev = buf[0];
			}
		}
		//n = Integer.parseInt(st.nextToken());
		return ;
	}
}

