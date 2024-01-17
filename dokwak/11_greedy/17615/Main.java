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
		char[] arr = br.readLine().toCharArray();
		int redCount = 0;
		int blueCount = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 'R')
				redCount++;
			else{
				blueCount++;
			}
		}
		int sol = Integer.MAX_VALUE;
		char mostLeftBall = arr[0];
		int leftLen = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i] == mostLeftBall)
				leftLen++;
			else
				break;
		}
		char mostRightBall = arr[n - 1];
		int rightLen = 1;
		for (int i = n - 2; i >= 0; i--){
			if (arr[i] == mostRightBall)
				rightLen++;
			else
				break;
		}
		if (mostLeftBall == 'R'){
			sol = Integer.min(sol, redCount - leftLen);
			sol = Integer.min(sol, blueCount);
		}
		else if (mostLeftBall =='B'){
			sol = Integer.min(sol, blueCount - leftLen);
			sol = Integer.min(sol, redCount);
		}
		if (mostRightBall == 'R'){
			sol = Integer.min(sol, redCount - rightLen);
			sol = Integer.min(sol, blueCount);
		}
		else if (mostRightBall == 'B'){
			sol = Integer.min(sol, blueCount - rightLen);
			sol = Integer.min(sol, redCount);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
