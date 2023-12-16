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
		String input = st.nextToken();
		int len = input.length();
		int felLen = 0;
		for (int i = 0; i < input.length(); i++) {
			int l = i;
			int r = input.length() - 1;
			while (l <= r){
				if (input.charAt(l) != input.charAt(r)){
					break;
				}
				l++;
				r--;
			}
			if (l > r){
				felLen = input.length() - 1 - i + 1;
//				sb.append("found fel : " + input.substring(i, input.length()));
//				sb.append("\n");
				break;
			}
		}
		int minFelLen = felLen + ((len - felLen) * 2);
		sb.append(minFelLen);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


