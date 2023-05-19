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
		for (int i = 0; i < n; i++) {
			Stack <Character> s = new Stack<>();
			String temp = br.readLine();
			for (int j = 0; j < temp.length(); j++) {
				Character c = temp.charAt(j);
				if (c == '(')
					s.push('(');
				else if (c == ')')
				{
					if (s.size() == 0)
					{
						sb.append("NO\n");
						break ;
					}
					else
						s.pop();
				}
				if (j == temp.length() - 1)
				{
					if (s.size() != 0)
						sb.append("NO\n");
					else
						sb.append("YES\n");
				}
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
