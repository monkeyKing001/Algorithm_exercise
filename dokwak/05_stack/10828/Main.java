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
		Stack<Integer> stack = new Stack<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			String cmd = st.nextToken();
			if (cmd.compareTo("push") == 0){
				int num = Integer.parseInt(st.nextToken());
				stack.push(num);
			}
			else if (cmd.compareTo("pop") == 0){
				if (!stack.empty()){
					sb.append(stack.pop());
				}
				else{
					sb.append(-1);
				}
				sb.append("\n");
			}
			else if (cmd.compareTo("size") == 0){
				sb.append(stack.size());
				sb.append("\n");
			}
			else if (cmd.compareTo("empty") == 0){
				if (!stack.empty()){
					sb.append(0);
				}
				else{
					sb.append(1);
				}
				sb.append("\n");
			}
			else if (cmd.compareTo("top") == 0){
				if (!stack.empty()){
					sb.append(stack.peek());
				}
				else{
					sb.append(-1);
				}
				sb.append("\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


