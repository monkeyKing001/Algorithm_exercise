import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int [] target = new int [100001];
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(br.readLine());
			target[i] = temp;
		}
		Stack <Integer> s = new Stack<>();
		int num = 0;
		s.push(num++);
		for (int i = 0; i < n; i++) {
			int temp = target[i];
			int find = 0;
			while (s.size() != 0 && s.peek() < temp)
			{
				s.push(num++);
				sb.append("+\n");
			}
			if (s.peek() == temp)
			{
				s.pop();
				sb.append("-\n");
			}
			else if (s.peek() != temp)
			{
				System.out.println("NO");
				return ;
			}
		}
		System.out.print(sb);
		return ;
	}
}

