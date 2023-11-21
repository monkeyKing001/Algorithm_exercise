import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
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
		ArrayList<Integer> arr = new ArrayList<>();
		Queue<int[]> q = new LinkedList<>();
		int map [][] = new int [n][n];
		int visited [][] = new int [n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++){
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			String info = br.readLine();
			for (int j = 0; j < n ; j++){
				if (info.charAt(j) == '1')
					map[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++){
				if (map[i][j] == 1 && visited[i][j] == 0){
					int[] start = new int[2];
					start[0] = i;
					start[1] = j;
					q.add(start);
					int area = 0;
//					System.out.println("start : ");
//					System.out.print(i);
//					System.out.print(", ");
//					System.out.println(j);
					while (q.size() != 0){
						int cur[] = q.poll();
						int cur_r = cur[0];
						int cur_c = cur[1];
						if (visited[cur_r][cur_c] != 0)
							continue;
						area++;
						visited[cur_r][cur_c] = 1;
						for (int ii = 0; ii < 4; ii++) {
							int next_r = cur_r + dr[ii];
							int next_c = cur_c + dc[ii];
							if (next_r < n && next_r > -1 && next_c < n && next_c >-1 
									&& visited[next_r][next_c] == 0 && map[next_r][next_c] == 1){
								int [] next_point = new int[2];
								next_point[0] = next_r;
								next_point[1] = next_c;
								q.add(next_point);
							}
						}
					}
//					System.out.println("area : " + area);
					arr.add(area);
				}
			}
		}
		arr.sort(Comparator.naturalOrder());
		sb.append(arr.size() + "\n");
		for (int i = 0; i < arr.size(); i++) {
			sb.append(arr.get(i));
			if (i != arr.size() - 1)
				sb.append(" ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


