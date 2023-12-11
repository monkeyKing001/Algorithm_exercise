import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		String str= br.readLine();


		//input
		Map<Character, Integer> map = new TreeMap<>();
		for (int i = 0; i < str.length(); i++) {
			map.put(str.charAt(i), map.getOrDefault(str.charAt(i), 0) + 1);
		}
		char[] buf = new char[str.length()];
		int oddNum = 0;
		for (Character chr : map.keySet()) {
			if (map.get(chr) % 2 == 1)
				oddNum++;
		}
		if (oddNum > 1) {
			sb.append("I'm Sorry Hansoo");
			bw.write(sb.toString());
			bw.flush();
			return ;
		}
		int l = 0;
		int r = str.length() -1;
		for (Character chr : map.keySet()) {
			while (map.get(chr) >= 2){
				buf[l] = chr;
				buf[r] = chr;
				l++;
				r--;
				map.put(chr, map.get(chr) - 2);
			}
		}
		for (Character chr : map.keySet()) {
			while (map.get(chr) == 1){
				buf[l] = chr;
				map.put(chr, 0);
			}
		}
		sb.append(buf);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


