import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static Set<String> visited;
	static boolean found = false;
	static int sol = -1;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		visited = new HashSet<>();
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] info = new int[n + 1];
		st = new StringTokenizer(br.readLine()," ");
		Queue<int[]> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			String str = st.nextToken();
			char chr = str.charAt(0);
			info[i] = chr;
		}
		info[n] = 0;
		q.add(info);
		while (q.size() != 0 && !found){
			int [] curInfo = q.poll();
			int curStep = curInfo[n];
			String bufStr = "";
			for (int i = 0; i < n; i++) {
				bufStr += (char)curInfo[i];
//				System.out.println("bufStr : " + bufStr);
			}
			if (visited.contains(bufStr))
				continue;
//			System.out.println("testing : " + bufStr);
			visited.add(bufStr);
			for (int i = 1; i < n; i++) {
				if (curInfo[i - 1] > curInfo[i])
					break;
				if (i == n - 1){
					found = true;
					sol = curStep;
//					System.out.println("made : " + bufStr);
					break;
				}
			}
			//flip
			for (int i = 0; i + m <= n ; i++) {
				int [] next_info = Arrays.copyOf(curInfo, n + 1);
				int l = i;
				int r = i + m - 1;
				next_info[n] = curStep + 1;
				while (l <= r){
					int temp = next_info[l];
					next_info[l++] = next_info[r];
					next_info[r--] = temp;
				}
				q.add(next_info);
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


