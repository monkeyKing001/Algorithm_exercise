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
		m = Integer.parseInt(st.nextToken());
		int sol = 0;
		//p robot
		//h components
		String str = br.readLine();
		char[] chr = str.toCharArray();
		for (int i = 0; i < n; i++) {
			if (chr[i] == 'P'){
				for (int j = i - m; j < i + m + 1; j++) {
					if (j >= 0 && j < n && chr[j] == 'H')
					{
						sol++;
						chr[j] = 0;
						break;
					}
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


