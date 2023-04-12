import java.util.*;
import java.io.*;

public class Main{
	static int n;
	static int m;
	static int[] buf = new int [10];
	static ArrayList<Integer> arr = new ArrayList<>();

	static void rec(int cur_i, int cur_n_i, int[] buf)
	{
		if (cur_i == m)
		{
			for (int i = 0; i < m; i++) {
				System.out.print(buf[i] + " ");
			}
			System.out.print("\n");
		}
		else
		{
			int prev = -1;
			for (int i = cur_n_i; i < n; i++) {
				if (prev == arr.get(i))
					continue;
				buf[cur_i] = arr.get(i);
				prev = arr.get(i);
				rec(cur_i + 1, i, buf);
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
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		arr.sort(Comparator.naturalOrder());

		//input
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (arr.get(i) == prev)
				continue ;
			buf[0] = arr.get(i);
			rec(0 + 1, i, buf);
			prev = arr.get(i);
		}
		//n = Integer.parseInt(st.nextToken());
		return ;
	}
}

