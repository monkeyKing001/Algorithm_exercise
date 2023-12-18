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
		String str = st.nextToken();
		Stack<Character> s = new Stack<>();
		Stack<Integer> num = new Stack<>();
		int pc = 1;
		int sol = 0;
		for (int i = 0; i < str.length(); i++) {
			char chr = str.charAt(i);
			//open
			if (chr == '(' || chr == '['){
				if (chr == '('){
					num.push(2);
				}
				else{
				}
			}
			//close
			else{
				//unmatch
				if (s.empty() || Math.abs(chr - s.peek()) > 2){
					sol = 0;
					break;
				}
				//match
				s.pop();
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


