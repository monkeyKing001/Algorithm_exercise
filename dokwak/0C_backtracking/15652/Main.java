import java.util.*;
import java.io.*;

public class Main{
	static int n = 0;
	static int m = 0;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		char[] buf = new char[10];
		for (int i = 0; i < n; i++){
			buf[0] = (char)(i + 1 + '0');
			rec(m, 1, i + 1, buf);
		}
		return ;
	}

	static void rec(int len, int cur_i, int cur_i_num, char[] buf)
	{
		if (cur_i == len)
		{
			for (int i = 0; i < len; i++) {
				System.out.print(buf[i] + " ");
			}
			System.out.print("\n");
		}
		else
		{
			for (int i = cur_i_num; i <= n; i++) {
				buf[cur_i] = (char)(i + '0');
				rec(len, cur_i + 1, i, buf);
			}
		}

	}
}

