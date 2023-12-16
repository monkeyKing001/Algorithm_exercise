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
		int num = 0;
		String str = st.nextToken();
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < str.length(); i++) {
			char chr = str.charAt(i);
			int chrToInt = 0;
			if (!Character.isDigit(chr)) {
				chrToInt = chr + 10 - 'A';
			}
			else{
				chrToInt = chr - '0';
			}
			num += chrToInt * Math.pow((double)n, str.length() - i - 1);
		}
		sb.append(num);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


