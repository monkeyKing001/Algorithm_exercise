import java.util.*;
import java.io.*;
import java.math.*;

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
		m = Integer.parseInt(st.nextToken());
		Deque<Integer> dq = new ArrayDeque<>();
		String str = br.readLine();
		for (int i = 0; i < n; i++) {
			int num = str.charAt(i) - '0';
			while (dq.size() != 0 && dq.peekLast() < num && m > 0){
				int pop = dq.removeLast();
				//System.out.println("poping : " + pop);
				m--;
			}
			dq.addLast(num);
//			System.out.println(dq.stream().toList());
		}
		while (m > 0){
			dq.removeLast();
			m--;
		}
		while (dq.size() != 0){
			System.out.print(dq.pollFirst());
		}
			
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
