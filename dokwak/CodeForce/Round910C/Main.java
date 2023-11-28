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
		int n = str.length();
		int arr[] = new int[str.length()];
		int dp[] = new int[str.length()];
		int start_i;
		int end_i;
		for (int i = 0; i < str.length(); i++) {
			int	num = 1 & str.charAt(i);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


