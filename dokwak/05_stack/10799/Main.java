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
		Stack<Integer> numStack = new Stack<>();
		Stack<Character> braceStack = new Stack<>();
		Stack<Character> s = new Stack<>();
		int sol = 0;
		for (int i = 0; i < str.length(); i++) {
			char chr = str.charAt(i);
			if (chr == '(')
				s.add(chr);
			else{
				if (str.charAt(i - 1) == '(') {
					s.pop();
					sol += s.size();
//					System.out.println("laser! layer  : " + s.size());
				}
				else if (str.charAt(i - 1) == ')'){
					s.pop();
					sol += 1;
//					System.out.println("end! layer  : " + s.size());
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


