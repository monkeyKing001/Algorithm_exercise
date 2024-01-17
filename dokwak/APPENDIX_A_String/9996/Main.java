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
		String pattern = br.readLine();
		st = new StringTokenizer(pattern, "*");
		String start = st.nextToken();
		String end = st.nextToken();
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			if (str.length() >= (start.length() + end.length()) && str.startsWith(start) && str.endsWith(end))
				System.out.println("DA");
			else
				System.out.println("NE");
		}
		for (int i = 0; i < 10; i++) {
			
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
