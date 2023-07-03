import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void rec(int start, int cur, int []choice, int []visited, int []cycled, int[]finished)
	{
		if (finished[cur] == 1) //no more travel
			return ;
		visited[cur] = 1;
		int next = choice[cur];
//		System.out.println("cur, next : " + cur + ", "+ next);
		if (visited[next] == 1 && finished[next] == 0)//found cycle
		{
//			System.out.println("found cycle! cur : " + cur);
			cycle(cur, choice, cycled, 0);
			finished[cur] = 1;
		}
		else
		{
			if (visited[next] != 1)
				rec(start, next, choice, visited, cycled, finished);
			finished[cur] = 1;
		}
	}

	public static void cycle(int cur, int []choice, int[] cycled, int acc)
	{
		if (cycled[cur] == 1) //end of cycle
			n -= acc;
		else{
			cycled[cur] = 1;
			int next = choice[cur];
//			System.out.println("travling cycle. cur : " + cur);
			cycle(next, choice, cycled, acc + 1);
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			int r = n;
			int [] choice = new int [n + 1];
			int [] visited = new int [n + 1];
			int [] cycled = new int [n + 1];
			int [] finished = new int [n + 1];
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				choice[i + 1] = Integer.parseInt(st.nextToken());
				cycled[i] = 0;
				finished[i] = 0;
			}
			for (int i = 1; i < r + 1; i++) {
				//visited init
				rec(i, i, choice, visited, cycled, finished);
			}
			sb.append(Integer.toString(n) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


