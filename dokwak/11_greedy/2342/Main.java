import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 100001 * 4;
	static int score = max;
	static int left = 0, right = 0;
	static int [][][]dp = new int[100001][5][5];
	static int [][]cost = new int [5][5];
//	static void sol(ArrayList<Integer> arr, int index, int cur_left, int cur_right)
//	{
//		if (index == arr.size())
//		{
////			System.out.println("left, right : " + cur_left + ", "+ cur_right);
////			System.out.println("cur score : " + score);
//			score = Integer.min(score, dp[index][cur_left][cur_right]);
////			System.out.println("after update cur score : " + score);
//			return ;
//		}
//
//		int target = arr.get(index);
//		int before_cost = dp[index][cur_left][cur_right];
//
//		//leftmove memo
//		if (cur_right != target){
//			int leftmove_cost = cost[cur_left][target];
//			if (before_cost + leftmove_cost < dp[index + 1][target][cur_right])
//			{
////				System.out.println("STAGE[" + index + "] leftmove cost : from, to, cost : " + cur_left +" -> " +
////						target + " : "+ cost[cur_left][target]);
//				dp[index + 1][target][cur_right] = before_cost + leftmove_cost;
//				sol(arr, index + 1, target, cur_right);
//			}
//		}
//		
//		//rightmove memo
//		if (cur_left != target){
//			int rightmove_cost = cost[cur_right][target];
//			if (before_cost + rightmove_cost < dp[index + 1][cur_left][target])
//			{
////				System.out.println("STAGE[" + index + "] rightmove cost : from, to, cost : " + cur_right +" -> " +
////						target + " : "+ cost[cur_right][target]);
//				dp[index + 1][cur_left][target] = before_cost + rightmove_cost;
//				sol(arr, index + 1, cur_left, target);
//			}
//		}
//	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());

		//cost matrix
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == 0)
					cost[i][j] = 0;
				else if (i == j)
					cost[i][j] = 1;
				else if (i == 0)
					cost[i][j] = 2;
				else if (i != 0 && j != 0 && Math.abs(i - j) == 2)
					cost[i][j] = 4;
				else
					cost[i][j] = 3;
			}
		}
		//dp matrix
		int cur_pos = (left * 5) + right;
		for (int i = 0; i < 100001; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					dp[i][j][k] = max;			
				}
			}
		}
		dp[0][0][0] = 0;
		ArrayList<Integer> arr = new ArrayList<>();
		int cur_stage = 0;
		while (st.hasMoreTokens())
		{
			int target  = Integer.parseInt(st.nextToken());
			if (target == 0)
				break;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					//leftmove
					int cost_to_movingL = dp[cur_stage][i][j] + cost[i][target];
					if (j != target && dp[cur_stage + 1][target][j] > cost_to_movingL)
						dp[cur_stage + 1][target][j] = cost_to_movingL;
					//rightmove
					int cost_to_movingR = dp[cur_stage][i][j] + cost[j][target];
					if (i != target && dp[cur_stage + 1][i][target] > cost_to_movingR)
						dp[cur_stage + 1][i][target] = cost_to_movingR;
				}
			}
			cur_stage++;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (score > dp[cur_stage][i][j])
					score = dp[cur_stage][i][j];
			}
		}
//		for (int i = 0; i < arr.size(); i++){
//			System.out.print(arr.get(i) + " ");
//		}
//		sol(arr, 0, 0, 0);
		System.out.println(score);
		return ;
	}
}
