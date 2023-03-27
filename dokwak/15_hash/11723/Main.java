import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringBuilder sb_input = new StringBuilder();
		sb.append("");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		n  = Integer.parseInt(br.readLine());
		Set<Integer> s = new HashSet<>();
		for (int i = 0; i < n; i++) {
			sb_input.append(br.readLine());
			sb_input.append("\n");
		}
		String buf = sb_input.toString();
		StringTokenizer st = new StringTokenizer(buf);
		for (int i = 0; i < n; i++) {
			String cmd = st.nextToken();
			int num;
			if (cmd.compareTo("add") == 0)
			{
				num = Integer.parseInt(st.nextToken());
				s.add(num);
			}
			else if (cmd.compareTo("remove") == 0)
			{
				num = Integer.parseInt(st.nextToken());
				if (s.contains(num))
					s.remove(num);
			}
			else if (cmd.compareTo("check") == 0)
			{
				num = Integer.parseInt(st.nextToken());
				if (s.contains(num))
					sb.append("1\n");
				else
					sb.append("0\n");
			}
			else if (cmd.compareTo("toggle") == 0)
			{
				num = Integer.parseInt(st.nextToken());
				if (s.contains(num))
					s.remove(num);
				else
					s.add(num);
			}
			else if (cmd.compareTo("all") == 0)
			{
				for (int j = 0; j < 20; j++) {
					s.add(j + 1);
				}
			}
			else if (cmd.compareTo("empty") == 0)
			{
				s.clear();
			}
		}
		System.out.print(sb);
		return ;
	}
}
