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
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		String a = st.nextToken();
		String b = st.nextToken();
		int sol  = Integer.MAX_VALUE;
		for (int i = 0; i <= b.length() - a.length(); i++) {
			int offset = i;
			int diff = 0;
			for (int j = 0; j < a.length(); j++) {
				if (b.charAt(j + offset) != a.charAt(j))
					diff++;
			}
			sol = Integer.min(diff, sol);
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


