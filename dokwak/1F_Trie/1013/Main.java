import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		//input
		StringBuilder sb = new StringBuilder();
		sb.append("");
		Map<Character, Integer> map = new TreeMap<>();
		char [] buf = new char[100];
		for (int i = 0; i < 100; i++) {
			buf[i] = 0;
		}
		String str = br.readLine();
		for (int i = 0; i < str.length(); i++) {
			char chr = str.charAt(i);
			map.put(chr, map.getOrDefault(chr, 0) + 1);
		}
		boolean possible = true;
		int odd_count = 0;
		for (Character chr : map.keySet()){
			if (map.get(chr) % 2 != 0){
				odd_count++;
			}
		}
		if (odd_count > 1){
				sb.append("I'm Sorry Hansoo");
				possible = false;
		}
		int l = 0;
		int r = str.length() - 1;
		for (Character chr : map.keySet()){
			while (map.getOrDefault(chr, 0) >= 2){
				buf[l] = chr;
				buf[r] = chr;
				l++;
				r--;
				map.put(chr, map.getOrDefault(chr, 0) - 2);
			}
		}
		for (Character chr : map.keySet()){
			while (map.getOrDefault(chr, 0) != 0){
				buf[l] = chr;
				l++;
				map.put(chr, map.getOrDefault(chr, 0) - 1);
			}
		}
		for (int i = 0; i < str.length() && possible; i++) {
			sb.append(buf[i]);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
