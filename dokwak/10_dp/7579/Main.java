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
		int []mem = new int[n + 1];
		int []cost = new int[n + 1];
		int []dp2 = new int[10001];
		int cost_sum = 0;
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			mem[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
			cost_sum += cost[i];
		}
		//init
		for (int j = 0; j < 10001; j++) {
			dp2[j] = 0;
		}
		int cur_cost_sum = 0;
		for (int i = 0; i < n; i++) {
			int app_mem = mem[i];
			int app_cost = cost[i];
//			System.out.println("app mem : " + app_mem);
//			System.out.println("app cost : " + app_cost);
			int original_mem = dp2[cur_cost_sum];
			for (int j = cur_cost_sum + app_cost; j <= cost_sum; j++) {
				dp2[j] = original_mem + app_mem;
//				System.out.println("dp2[" + j + "] : " + dp2[j]);
			}
			int index = app_cost + cur_cost_sum - 1;
			//index = app_cost  + cur_cosT_sum - 1 = 10
			//cur_cost_sum = 6
			//app_cost = 5
			//c
			while (index - app_cost > -1 && app_mem + dp2[index - app_cost] > dp2[index])
			{
				dp2[index] = app_mem + dp2[index - app_cost];
//				System.out.println("dp2[" + index + "] : " + dp2[index]);
				index--;
			}
			cur_cost_sum += app_cost;
//			System.out.println("cur cost sum : " + cur_cost_sum);
		}
		for (int i = 0; i < cost_sum; i++) {
			if (dp2[i] >= m)
			{
				System.out.println(i);
				return ;
			}
		}
		return ;
	}
}
