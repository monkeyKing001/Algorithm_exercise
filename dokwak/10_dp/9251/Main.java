import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static char[] dp = new char[1001];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
//
//		//input
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());
		String input1 = br.readLine();
		input1 = "0".concat(input1);
		String input2 = br.readLine();
		input2 = "1".concat(input2);
		int [][]dp = new int [1001][1001];
		for (int i = 0; i < input1.length(); i++) {
			for (int j = 0; j < input2.length(); j++) {
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else
				{
					if (input1.charAt(i) == input2.charAt(j))
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = Integer.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		System.out.println(dp[input1.length() - 1][input2.length() - 1]);
//		int i = input1.length() - 1;
//		int j = input2.length() - 1;
//		while (dp[i][j] != 0)
//		{
//			int cur_num = dp[i][j];
//			if (dp[i - 1][j] == dp[i][j - 1])
//			{
//				sb.append(input1.charAt(i));
//				i--;
//				j--;
//			}
//			else if (dp[i - 1][j] == cur_num)
//				i--;
//			else if (dp[i][j - 1] == cur_num)
//				j--;
//		}
//		for (int k = 0; k < sb.length(); k++) {
//			System.out.print(sb.charAt(sb.length() - 1 - k));
//		}
		return ;
	}
}
