import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			DecimalFormat df = new DecimalFormat("00");
			st = new StringTokenizer(br.readLine()," ");
			int h = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			int cur_h = (num % h);
			int cur_w = (num / h) + 1;
			if (cur_h == 0){
				cur_h = h;
				cur_w--;
			}
			sb.append(cur_h);
			sb.append(df.format(cur_w) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


