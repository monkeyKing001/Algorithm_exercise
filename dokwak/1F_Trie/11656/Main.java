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
		Set<String> set = new TreeSet<>();
		for (int i = 0; i < str.length(); i++) {
			String sub = str.substring(i, str.length());
			set.add(sub);
		}
		Iterator <String> suffix = set.iterator();
		while (suffix.hasNext()){
			sb.append(suffix.next());
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


