import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		//input
		String words[] = new String[5];
		for (int i = 0; i < 5; i++) {
			words[i] = br.readLine();
		}
		for (int i = 0; i < 15; i++) {
			for (int str_i = 0; str_i < 5; str_i++) {
				if (i < words[str_i].length())
					sb.append(Character.toString(words[str_i].charAt(i)));
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


