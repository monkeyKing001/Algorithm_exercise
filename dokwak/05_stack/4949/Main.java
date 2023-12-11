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
		String str = br.readLine();
		while (str != null){
			Stack<Character> s = new Stack<>();
			int i = 0;
			boolean balance = true;
			if (str.length() == 1 && str.charAt(0) == '.')
				break;
			while (i < str.length()){
				if (str.charAt(i) == '(' || str.charAt(i) == '[')
					s.push(str.charAt(i));
				else if (str.charAt(i) == ')' || str.charAt(i) == ']'){
					if (str.charAt(i) == ')'){
						if (s.size() != 0 && s.peek() == '(')
							s.pop();
						else
						{
							balance = false;
							break;
						}
					}
					else if (str.charAt(i) == ']'){
						if (s.size() != 0 && s.peek() == '[')
							s.pop();
						else
						{
							balance = false;
							break;
						}
					}
				}
				i++;
			}
			if (s.size() == 0 && balance){
				sb.append("yes\n");
			}
			else
				sb.append("no\n");
			str = br.readLine();
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


