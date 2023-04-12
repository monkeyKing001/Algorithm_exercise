//start 03:13
//end 04:20
import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		//input
		String input = br.readLine();
		Stack <Character> s = new Stack<>();
		for (int i = 0; i < input.length(); i++) {
			Character c = input.charAt(i);
			// "(" case
			if (Character.compare(c, '(') == 0)
				s.push(c);
			// "(" case
			else if (Character.compare(c, '*') == 0 
					|| Character.compare(c, '/') == 0)
			{
				while(s.size() != 0 && (Character.compare(s.peek(), '*') == 0 || Character.compare(s.peek(), '/') == 0))
					sb.append(s.pop().toString());
				s.push(c);
			}
			else if (Character.compare(c, '+') == 0 
					|| Character.compare(c, '-') == 0)
			{
				while(s.size() != 0 && Character.compare(s.peek(), '(') != 0)
					sb.append(s.pop().toString());
				s.push(c);
			}
			else if (Character.compare(c, ')') == 0)
			{
				while (s.size() != 0 && Character.compare(s.peek(), '(') != 0)
					sb.append(s.pop().toString());
				s.pop();//pop out '('
			}
			else// operand case (ex. A, B, C ... etc)
			{
				sb.append(c.toString());
			}
		}
		while (s.size() != 0)
			sb.append(s.pop().toString());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


