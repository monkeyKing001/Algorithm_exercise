import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 111111111;
	static int [][] g;
	static int [][] dp;
	static int allVisitedBits;
	static int notVisited = -1;
	static int sol = Integer.MAX_VALUE;

	//결국, 이 getCost 함수가 주는 값은,
	//1. 현재 cur 위치에 있고
	//2. 지금까지 방문한 노드들은 visited_bits와 같을 때
	//3. 아직 방문하지 않은 모든 노드들을 다 순회하고 다시 0으로 돌아갔을 때의 비용을 returng 해준다.
	public static int getCost(int cur, int visited_bits){
		//base case
		if (visited_bits == allVisitedBits) {
			//return g[cur][0];
			dp[cur][visited_bits] = g[cur][0];
		}
		//if visited return the cost.
		if (dp[cur][visited_bits] != notVisited)
			return dp[cur][visited_bits];
		dp[cur][visited_bits] = max;
		//else, visit all the not visited node and go back to 0;
		//next_i로 갔다고 했을때, 그럼 거기서 구해온 getCost(next_i, visited_bits | next_i) + g[cur][next]를 구하면,
		//우리가 궁극적으로 구하고 싶었던 값,
		//dp[cur][visited_bits]
		//cur위치에 있고 visited_bits를 방문했을 때 방문하지 않은 나머지 모든 노드들을 방문하고 0으로 돌아가는 비용
		//을 구할 수 있다.
		for (int next = 0; next < n; next++) {
			//not visited
			if (((visited_bits >> next) & 1) == 0 && g[cur][next] != max){
				dp[cur][visited_bits] = Integer.min(
						dp[cur][visited_bits], 
						getCost(next, (visited_bits) | 1 << next) + g[cur][next] 
						);
			}
		}
		return (dp[cur][visited_bits]);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		g = new int[n][n];
		dp = new int[n][1 << n];
		allVisitedBits = (1 << n) - 1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n ; j++) {
				g[i][j] = Integer.parseInt(st.nextToken());
				if (i != j && g[i][j] == 0)
					g[i][j] = max;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << n); j++) {
				dp[i][j] = notVisited;
			}
		}
		//cur point can be anywhere because traveling will be cycle.
		getCost(0, 1);
		sol = dp[0][1];
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
