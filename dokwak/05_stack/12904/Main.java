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
		Stack<Character> stack = new Stack<>();
		Stack<Character> garbage = new Stack<>();
		Stack<Character> temp = new Stack<>();
		String s = br.readLine();
		String t = br.readLine();
		for (int i = 0; i < t.length(); i++) {
			char chr = t.charAt(i);
			stack.add(chr);
		}
		while (stack.size() != s.length()){
			char token = stack.pop();
			if (token == 'B'){
				while (stack.size() != 0){
					garbage.push(stack.pop());
				}
				temp = stack;
				stack = garbage;
				garbage =  temp;
			}
		}
		int s_i = s.length() - 1;
		int sol = 1;
		while (stack.size() != 0)
		{
			char token = stack.pop();
//			System.out.println("checking chars : " + token);
			if (s.charAt(s_i--) != token)
			{
				sol = 0;
				break ;
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


