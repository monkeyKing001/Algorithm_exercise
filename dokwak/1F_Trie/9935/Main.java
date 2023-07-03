import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		//input
		String str = br.readLine();
		String del = br.readLine();
		StringBuilder sb = new StringBuilder();
		Stack<Character> s1 = new Stack<>();
		int del_i = del.length() - 1;
		for (int i = 0; i < str.length(); i++) {
			sb.append(str.charAt(i));
			if (sb.charAt(sb.length() - 1) == del.charAt(del_i) && sb.length() >= del.length())
			{
				int sb_i = sb.length() - 1;
				while (del_i > -1 && sb.charAt(sb_i) == del.charAt(del_i))
				{
					s1.add(sb.charAt(sb_i));
					sb.delete(sb_i, sb_i + 1);
					sb_i--;
					del_i--;
				}
				//delimeter made
				if (del_i == -1)
					s1.clear();
				while (s1.size() != 0)
					sb.append(s1.pop());
				del_i = del.length() - 1;
			}
		}
		String sol = sb.toString();
		if (sol.length() == 0)
			sol = "FRULA";
		System.out.println(sol);
		return ;
	}
}
