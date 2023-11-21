import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class Main{
	static int n, m;
	//				   >  ^  <   v
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		Set<String> visited = new HashSet<String>();
		Stack<Integer> score = new Stack<>();
		Stack<Integer> rStack = new Stack<>();
		Stack<Integer> cStack = new Stack<>();
		int cur_c = 0;
		int cur_r = 0;
		rStack.push(0);
		cStack.push(0);
		score.push(1);
		visited.add("0,0");
		String info = br.readLine();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int cur_score = Integer.parseInt(st.nextToken());
			char dir = info.charAt(i);
			int next_dir = 0;
			if (dir == 'U')
				next_dir = 1;
			else if (dir == 'L')
				next_dir = 2;
			else if (dir == 'D') 
				next_dir = 3;
			int next_r = cur_r + dr[next_dir];
			int next_c = cur_c + dc[next_dir];
			String nextPoint = Integer.toString(next_r) + "," + Integer.toString(next_c);
			while (visited.contains(nextPoint)){
				String popR = Integer.toString(rStack.pop());
				String popC = Integer.toString(cStack.pop());
				score.pop();
				String popPoint = popR + "," + popC;
//				System.out.println("popPoint : " + popPoint);
				visited.remove(popPoint);
			}
			score.push(cur_score);
			rStack.push(next_r);
			cStack.push(next_c);
//			System.out.println("push : " + nextPoint);
			visited.add(nextPoint);
			cur_r = next_r;
			cur_c = next_c;
		}
		int sol = 0;
		while (score.size() != 0){
			sol += score.pop();
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


