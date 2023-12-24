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
		Set<Integer> set = new HashSet<Integer>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			set.add(num);
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < m; i++) {
			int num = Integer.parseInt(st.nextToken());
			if (set.contains(num))
				System.out.print("1 ");
			else
				System.out.print("0 ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


