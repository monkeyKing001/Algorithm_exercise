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
		String str = br.readLine();
		int [] count = new int[26];
		int max = 0;
		while (str != null){
			str = str.replaceAll(" ", "");
//			System.out.println(str);
			for (int i = 0; i < str.length(); i++) {
				char chr = str.charAt(i);
				int idx = chr - 'a';
				count[idx]++;
				max = Integer.max(max, count[idx]);
			}
			str = br.readLine();
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] == max){
				sb.append((char)(i + 'a'));
			}
		}
		System.out.println(sb);
		return ;
	}
}
