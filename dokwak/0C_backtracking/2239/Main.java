import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());
		int [][]board = new int[10][10];
		for (int i = 1; i < 10; i++) {
			String temp = br.readLine();
			for (int j = 1; j < 10; j++) {
				board[i][j] = temp.charAt(j - 1) - '0';
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


