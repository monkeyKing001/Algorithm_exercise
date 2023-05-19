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
		int sol = 0;
		for (int i = 0; i < n; i++) {
			TreeSet<Character> s = new TreeSet<>();
			String input = br.readLine();
			int index = 0;
			while (index < input.length())
			{
				Character c = input.charAt(index);
				if (s.contains(c) == true)
					break ;
				else
				{
					s.add(c);
					while (index < input.length() && input.charAt(index) == c)
						index++;
				}
				if (index == input.length())
				{
					sol++;
//					System.out.println("stirng : " + input);
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
