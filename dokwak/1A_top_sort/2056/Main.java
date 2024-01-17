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
		int [] indegree = new int[n + 1];
		int [] time = new int[n + 1];
		int [] startTimeForNode = new int[n + 1];
		ArrayList<Integer> g[] = new ArrayList[n + 1];
		for (int i = 1; i < n + 1; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int costTime = Integer.parseInt(st.nextToken());
			time[i] = costTime;
			int indegreeNum = Integer.parseInt(st.nextToken());
			indegree[i] = indegreeNum;
			for (int d_i = 0; d_i < indegreeNum; d_i++) {
				int from_v = Integer.parseInt(st.nextToken());
				g[from_v].add(i);
			}
		}
		int totalTime = 0;
		Queue<int[]> q = new LinkedList<>();//cur, cur_time
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0){
				int start[] = new int[2];
				start[0] = i;
				start[1] = 0;
				q.add(start);
				totalTime = Math.max(totalTime, time[i]);
			}
		}
		while (!q.isEmpty()){
			int curInfo[] = q.poll();
			int cur = curInfo[0];
			int startTime = curInfo[1];
			int endTime = startTime + time[cur];
			totalTime = Math.max(totalTime, endTime);
//			System.out.println("cur, time : " + cur + ", " + startTime + " ~ " + endTime);
			for (int next_i = 0; next_i < g[(int)cur].size(); next_i++) {
				int next = g[(int)cur].get(next_i);
				indegree[next]--;
				startTimeForNode[next] = Math.max(startTimeForNode[next], endTime);
				if (indegree[next] == 0){
					int nextInfo[] = new int[2];
					nextInfo[0] = next;
					nextInfo[1] = startTimeForNode[next];
					q.add(nextInfo);
				}
			}
		}
		System.out.println(totalTime);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


