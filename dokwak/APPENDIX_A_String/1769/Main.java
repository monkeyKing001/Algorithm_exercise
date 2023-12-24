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
		String str = st.nextToken();
		int stepCount = 0;
		while (str.length() != 1){
			int num = 0;
			stepCount++;
			for (int i = 0; i < str.length(); i++) {
				num += str.charAt(i) - '0';
			}
			String nextStr = Integer.toString(num);
			str = nextStr;
		}
		sb.append(stepCount + "\n");
		if (Integer.parseInt(str) % 3 == 0){
			sb.append("YES");
		}
		else
			sb.append("NO");
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


