import java.util.*;
import java.io.*;

public class Main{
	static int n;
	static int m;
	static ArrayList<Integer> arr;
	static TreeSet<Integer> s;
	public static void rec(int len, int[] buf){
		if (len == m){
			for (int i = 0; i < m; i++) {
				System.out.print(buf[i] + " ");
			}
			System.out.println();
			return ;
		}
		int last_num = buf[len - 1];
		int next_num;
		int []cp = new int[m];
		for (int i = 0; i < len; i++) {
			cp[i] = buf[i];
		}
		Iterator <Integer> it = s.iterator();
		while (it.hasNext()){
			next_num = it.next();
			if (next_num < last_num)
				continue;
			cp[len] = next_num;
			rec(len + 1, cp);
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
		s = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			s.add(Integer.parseInt(st.nextToken()));
		}

		//input
		int prev = -1;
		int [] buf = new int[m];
		Iterator<Integer> it = s.iterator();
		while (it.hasNext()){
			int num = it.next();
			buf[0] = num;
			rec(1, buf);
		}
		//n = Integer.parseInt(st.nextToken());
		return ;
	}
}

