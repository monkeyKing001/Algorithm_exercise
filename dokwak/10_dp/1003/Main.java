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
		n = Integer.parseInt(st.nextToken());
		int T = n;
		int dpOne[] = new int[45];
		int dpZero[] = new int[45];
		dpZero[0] = 1;
		dpZero[1] = 0;
		dpOne[0] = 0;
		dpOne[1] = 1;
		for (int i = 2; i < 45; i++) {
			dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
			dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
		}
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			sb.append(dpZero[m] + " " + dpOne[m] + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


