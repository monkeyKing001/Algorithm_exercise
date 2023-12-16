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
		Set<String> set = new HashSet<String>();
		String str = st.nextToken();
		for (int size = 1; size <= str.length(); size++) {
			for (int start = 0; start + size <= str.length(); start++) {
				int end = start + size;
				String substr = str.substring(start, end);
				set.add(substr);
			}
		}
		sb.append(set.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


