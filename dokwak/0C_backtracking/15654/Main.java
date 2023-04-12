import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> arr = new ArrayList<>();
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(st.nextToken());
			arr.add(temp);
		}
		arr.sort(Comparator.naturalOrder());
		int []buf = new int[10];
		for (int i = 0; i < n; i++) {
			buf[0] = arr.get(i);
			rec(0 + 1, m, buf);
		}
//		for (int i = 0; i < n; i++) {
//			System.out.println(arr.get(i));
//		}
		return ;
	}
	static void rec(int start, int len, int [] buf)
	{
		if (start == len)
		{
			for (int i = 0; i < m; i++) {
				System.out.print(buf[i] + " ");
			}
			System.out.println("");
			return ;
		}
		else {
			for (int i = 0; i < n; i++) {
				boolean go = true;
				buf[start] = arr.get(i);
				for (int j = 0; j < start; j++) {
					if (buf[start] == buf[j])
						go = false;
				}
				if (go == true)
					rec(start + 1, len, buf);
			}
		}
	}
}

