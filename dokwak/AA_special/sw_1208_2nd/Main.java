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
		int T = 10;
		for (int t_i = 0; t_i < 10; t_i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine()," ");
			int [] heights_num = new int [101];
			for (int i = 0; i < 101; i++) {
				heights_num[i] = 0;
			}
			for (int i = 0; i < 100; i++) {
				int h = Integer.parseInt(st.nextToken());
				heights_num[h]++;
			}
			int l = 1;
			int r = 100;
			while (heights_num[r] == 0)
				r--;
			while (heights_num[l] == 0)
				l++;
			while (n > 0 && l + 1 != r){
				heights_num[l]--;
				heights_num[l + 1]++;
				heights_num[r - 1]++;
				heights_num[r]--;
				if (heights_num[l] == 0)
					l++;
				if (heights_num[r] == 0)
					r--;
				n--;
			}
			System.out.println("#" + (t_i + 1) + " " + (r - l));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


