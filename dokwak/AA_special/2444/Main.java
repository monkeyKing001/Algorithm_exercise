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
		int max_length = (2 * n) - 1;
		for (int row = 0; row < 2 * n - 1; row++) {
			if (row < n){
				int space = n - row - 1;
				int star = row * 2 + 1;
				for (int i = 0; i < space; i++)
					sb.append(" ");
				for (int i = 0; i < star; i++) 
					sb.append("*");
			}
			else{
				int space = row - n + 1;
				int star = max_length - (2 * space);
				for (int i = 0; i < space; i++)
					sb.append(" ");
				for (int i = 0; i < star; i++) 
					sb.append("*");
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


