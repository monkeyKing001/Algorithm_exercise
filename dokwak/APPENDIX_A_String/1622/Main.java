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
		while(str != null){
			String nextStr = br.readLine();
			int info1[] = new int[26];
			int info2[] = new int[26];
			for (int i = 0; i < str.length(); i++){
				info1[str.charAt(i) - 'a']++;
			}
			for (int i = 0; i < nextStr.length(); i++) {
				info2[nextStr.charAt(i) - 'a']++;
			}
			String buf = "";
			for (int i = 0; i < 26; i++){
				while(info1[i] != 0 && info2[i] != 0){
					buf += (char)(i + 'a');
					info1[i]--;
					info2[i]--;
				}
			}
			System.out.println(buf);
			str = br.readLine();
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


