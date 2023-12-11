import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str,"+-");
		Queue<Character> oper = new LinkedList<>();
		Stack<Integer> minus = new Stack<>();
		Stack<Integer> plus = new Stack<>();
		Stack<Integer> s = new Stack<>();
		boolean plusPro = true;
		int l = 0;
		while (l < str.length()){
			if (str.charAt(l) == '+' || str.charAt(l)== '-')
				oper.add(str.charAt(l));
			l++;
		}
		//input
		plus.push(0);
		minus.push(0);
		s = plus;
		while (st.hasMoreTokens()){
			n = Integer.parseInt(st.nextToken());
			n += s.pop();
			s.push(n);
			if (oper.size() != 0){
				char operator = oper.poll();
				if (operator == '-' && plusPro)
					s = minus;
				else if (operator == '+' && !plusPro){
					n = Integer.parseInt(st.nextToken());
					n += s.pop();
					s.push(n);
					plusPro = true;
				}
			}
		}
		sb.append(plus.pop() - minus.pop());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


