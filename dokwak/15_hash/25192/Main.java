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
		Set<String> s = new HashSet<>();
		int sol = 0;
		for (int i = 0; i < n; i++) {
			String temp = br.readLine().toString();
			if (temp.compareTo("ENTER") == 0)
			{
				sol += s.size();
				s.clear();
			}
			else
				s.add(temp);
		}
		sol += s.size();
		s.clear();
		System.out.print(sol);
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}


