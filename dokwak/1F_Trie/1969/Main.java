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
		m = Integer.parseInt(st.nextToken());
		int [][] dp = new int[m][4]; //A C G T
		String gene = "ACGT";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 4 ; j++){
					dp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				if (str.charAt(j) == 'A'){
					dp[j][0]++;
				}
				else if (str.charAt(j) == 'C'){
					dp[j][1]++;
				}
				else if (str.charAt(j) == 'G'){
					dp[j][2]++;
				}
				else if (str.charAt(j) == 'T'){
					dp[j][3]++;
				}
			}
		}
		int sol = 0;
		for (int i = 0; i < m; i++) {
			int max = - 1;
			int max_char = -1;
			for (int j = 0; j < 4; j++) {
				if (dp[i][j] > max){
					max = dp[i][j];
					max_char = j;
//					System.out.println("max char in " + i + " = " + gene.charAt(max_char));
				}
			}
			sb.append(gene.charAt(max_char));
			for (int j = 0; j < 4; j++) {
				if (j != max_char) {
					sol += dp[i][j];
				}
			}
		}
		sb.append("\n");
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


