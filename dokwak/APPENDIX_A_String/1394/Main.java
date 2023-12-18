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
		String base = st.nextToken();
		long mod = 900528l;
		st = new StringTokenizer(br.readLine()," ");
		String code = st.nextToken();
		Map<Character, Long> map = new HashMap<Character, Long>();
		for (int i = 0; i < base.length(); i++) {
			char chr = base.charAt(i);
			map.put(chr, (long)map.size() + 1);
		}
		long len = base.length();
		long sol = 0;
		for (int i = 0; i < code.length(); i++) {
			char chr = code.charAt(i);
			sol *= len;
			sol %= mod;
			sol += map.get(chr);
			sol %= mod;
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
