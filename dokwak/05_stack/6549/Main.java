import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		long [] tower = new long [100001];
		int [] r_small = new int [100001]; 
		int [] l_small = new int [100001]; 
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		String buf = br.readLine();
		while (buf != null)
		{
			StringTokenizer st = new StringTokenizer(buf," ");
			n = Integer.parseInt(st.nextToken()); 
			Stack <Integer> s = new Stack<>();
			Stack <Integer> s2 = new Stack<>();
			for (int i = 0; i < n; i++) {
				int h = Integer.parseInt(st.nextToken());
				tower[i] = (long)h;
				r_small[i] = n;
				while (s.size() != 0 && tower[s.peek()] > h)
				{
					r_small[s.peek()] = i;
					s.pop();
				}
				s.push(i);
			}
			for (int i = 0; i < n; i++) {
				long h = tower[n - 1 - i];
				l_small[n - 1 - i] = -1;
				while (s2.size() != 0 && tower[s2.peek()] > h)
				{
					l_small[s2.peek()] = n - 1 - i;
					s2.pop();
				}
				s2.push(n - 1 - i);
			}
			long temp_max = 0;
			int len = 0;
			int temp_max_i = 0;
			for (int i = 0; i < n; i++) {
				long area = tower[i] * (r_small[i] - l_small[i] - 1);
				if (temp_max < area)
					temp_max = area;
			}
			buf = br.readLine();
			if (n != 0)
			{
				System.out.println(temp_max);
//				for (int i = 0; i < n; i++) {
//					System.out.print(r_small[i] + " ");
//				}
//				System.out.print("\n");
//				for (int i = 0; i < n; i++) {
//					System.out.print(l_small[i] + " ");
//				}
//				System.out.print("\n");
			}
		}
		return ;
	}
}
