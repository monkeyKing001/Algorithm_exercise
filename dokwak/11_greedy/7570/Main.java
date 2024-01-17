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
		int visited[] = new int[n + 1];
		int longestIncreasingNumInRow = 1;
		int lastNum = -1;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			visited[num] = visited[num - 1] + 1;
			longestIncreasingNumInRow = Integer.max(longestIncreasingNumInRow, visited[num]);
		}
		System.out.println(n - longestIncreasingNumInRow);
//		System.out.println("lastNum : " + lastNum);
//		System.out.println("longest IncreasingNumInRow : "  + longestIncreasingNumInRow);
		bw.flush();
		return ;
	}
}
