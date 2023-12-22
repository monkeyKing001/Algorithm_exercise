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
		String hay = br.readLine();
		String needle  = br.readLine();
		int l = 0;
		int sol = 0;
		while (l + needle.length() <= hay.length()){
			String substr = hay.substring(l, l + needle.length());
			if (substr.compareTo(needle) == 0){
				sol++;
				l = l + needle.length();
			}
			else
				l++;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


