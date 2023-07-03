import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int cur_size = 2;
	static int feed_size = 2;
	static int []dr = {0, 1, 0, -1};
	static int []dc = {1, 0, -1, 0};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int [][]map = new int[21][21];
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int[]e1, int[]e2)
			{
				if (e1[2] == e2[2]){
					if (e1[0] == e2[0])
						return (Integer.compare(e1[1], e2[1]));
					else
						return (Integer.compare(e1[0], e2[0]));
				}
				else{
					return (Integer.compare(e1[2], e2[2]));
				}
			}
		});
		Queue <int[]> q = new LinkedList<>();
		int [] start = new int[3];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 9)
				{
					start[0] = i;
					start[1] = j;
					start[2] = 0;
					map[i][j] = 0;
				}
			}
		}
		int sol = 0;
		while (true){
			int [][]visited = new int [n + 1][n + 1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					visited[i][j] = 0;
				}
			}
			//find feed;
//			System.out.println("start r, c : " + start[0] +", "+ start[1]);
			q.add(start);
			while (q.size() != 0)
			{
				int [] cur = q.peek();
				q.poll();
				for (int i = 0; i < 4; i++) {
					int next_r = cur[0] + dr[i];
					int next_c = cur[1] + dc[i];
					int next_step = cur[2] + 1;
					if (next_r < n && next_r >= 0 && next_c < n && next_c >= 0
							&& map[next_r][next_c] <= cur_size && visited[next_r][next_c] == 0)
					{
						int []next = new int[3];
						next[0] = next_r;
						next[1] = next_c;
						next[2] = next_step;
						if (map[next_r][next_c] == 0 || map[next_r][next_c] == cur_size)
						{
							q.add(next);
							visited[next_r][next_c] = 1;
						}
						else
							pq.add(next);
					}
				}
			}
			//eat
			//no feed
			if (pq.size() == 0)
			{
//				System.out.println("no more feed!");
				break;
			}
			int []target = pq.poll();
			start[0] = target[0];
			start[1] = target[1];
			start[2] = 0;
			feed_size--;
//			System.out.println("target r, c : " + start[0] +", "+ start[1]);
			sol += target[2];
//			System.out.println("total step : " + sol);
			map[target[0]][target[1]] = 0;
			pq.clear();
			if (feed_size == 0)
			{
				cur_size++;
				feed_size = cur_size;
//				System.out.println("##### size up ! : " + cur_size);
			}
		}
		System.out.println(sol);
		return ;
	}
}
