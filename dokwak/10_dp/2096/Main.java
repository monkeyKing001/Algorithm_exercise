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
		int maxDp [][] = new int [100001][3];
		int minDp [][] = new int [100001][3];
		int g [][] = new int[100001][3];
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < 3; j++) {
				int score = Integer.parseInt(st.nextToken());
				g[i][j] = score;
			}
		}
		for (int i = 0; i < 3; i++) {
			maxDp[0][i] = g[0][i];
			minDp[0][i] = g[0][i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) {
					maxDp[i][j] = Integer.max(maxDp[i - 1][0], maxDp[i - 1][1]);
					maxDp[i][j] += g[i][j];
					minDp[i][j] = Integer.min(minDp[i - 1][0], minDp[i - 1][1]);
					minDp[i][j] += g[i][j];
				}
				else if (j == 1){
					maxDp[i][j] = Integer.max(maxDp[i - 1][0], maxDp[i - 1][1]);
					maxDp[i][j] = Integer.max(maxDp[i][j], maxDp[i - 1][2]);
					maxDp[i][j] += g[i][j];
					minDp[i][j] = Integer.min(minDp[i - 1][0], minDp[i - 1][1]);
					minDp[i][j] = Integer.min(minDp[i][j], minDp[i - 1][2]);
					minDp[i][j] += g[i][j];
				}
				else if (j == 2){
					maxDp[i][j] = Integer.max(maxDp[i - 1][1], maxDp[i - 1][2]);
					maxDp[i][j] += g[i][j];
					minDp[i][j] = Integer.min(minDp[i - 1][1], minDp[i - 1][2]);
					minDp[i][j] += g[i][j];
				}
			}
		}
		int maxSol = maxDp[n - 1][0];
		maxSol = Integer.max(maxSol, maxDp[n - 1][1]);
		maxSol = Integer.max(maxSol, maxDp[n - 1][2]);
		int minSol = minDp[n - 1][0];
		minSol = Integer.min(minSol, minDp[n - 1][1]);
		minSol = Integer.min(minSol, minDp[n - 1][2]);
		sb.append(maxSol + " " + minSol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


