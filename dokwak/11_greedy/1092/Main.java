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
		ArrayList<Integer> c = new ArrayList<>();
		ArrayList<Integer> b = new ArrayList<>();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			c.add(num);
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < m; i++) {
			int num = Integer.parseInt(st.nextToken());
			b.add(num);
		}
		c.sort(Comparator.reverseOrder());
		b.sort(Comparator.reverseOrder());
		if (c.get(0) < b.get(0)){
			System.out.println(-1);
			return;
		}
//		System.out.println(c);
//		System.out.println(b);
		int count = 0;
		while (b.size() != 0){
			boolean keep = true;
			for (int c_i = 0; c_i < c.size() && keep == true; c_i++) {
				int limit = c.get(c_i);
				for (int b_i = 0; b_i < b.size(); b_i++) {
					int w = b.get(b_i);
					if (limit >= w){
//						System.out.println("removing " + b.get(b_i));
						b.remove(b_i);
						break;
					}
					if (b_i == b.size() - 1)
						keep = false;
				}
			}
			count++;
//			System.out.println("######        "+count + "      #######");
		}
		System.out.println(count);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


