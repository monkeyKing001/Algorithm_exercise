import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int n = 0;
		int [] tower = new int[500001];
		int	[] rec = new int[500001];

		//input
		//n = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		Stack <Integer> s = new Stack<>();
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(st.nextToken());
			tower[i + 1] = temp;
		}
		for (int i = 0; i < n; i++) {
			int h = tower[n - i];
			rec[n - i] = 0;
			while (s.size() != 0 && tower[s.peek()] < h)
			{
				rec[s.peek()] = n - i;
				s.pop();
			}
			s.push(n - i);
		}
		for (int i = 0; i < n; i++) {
			sb.append(rec[i + 1]);
			if (i != n - 1)
				sb.append(" ");
		}
		System.out.print(sb);
		return ;
	}
}

