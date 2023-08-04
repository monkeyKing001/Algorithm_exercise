import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []dr = {0, 1, -1, 0};
	static int []dc = {1, 0, 0, -1};
	public static class Game{
		public
			int [][]map;
			int [][]visited;
			int map_n;
			int map_m;
			int papers;
			Set<Integer> keys;
			Queue<int[]> start_points;
			ArrayList<int[]> doors;

		Game(int[][]_map, String _keys){
			//vars
			this.map_n = _map.length;
			this.map_m = _map[0].length;
			this.map = new int[map_n][map_m];
			this.visited = new int[map_n][map_m];
			this.keys = new HashSet<>();
			start_points = new LinkedList<>();
			doors = new ArrayList<>();
			this.papers = 0;

			//map read
			for (int i = 0; i < map_n; i++) {
				for (int j = 0; j < map_m; j++) {
					this.map[i][j] = _map[i][j];
					this.visited[i][j] = 0;
				}
			}

			//keys read
			for (int i = 0; i < _keys.length(); i++) {
				char key = _keys.charAt(i);
				this.keys.add((int)key);
			}

			//get start_points
			for (int i = 0; i < this.map_n; i++) {
				for (int j = 0; j < this.map_m; j++) {
				int token = this.map[i][j];
					if (i == 0 || i == this.map_n - 1 || j == 0 || j == this.map_m - 1){
						if ((token == '.' || 
							token == '$' || 
							(token >= 'a' && token <= 'z') ||
							(token >= 'A' && token <= 'Z' && this.keys.contains(token + ('a' - 'A')) == true ))){
//							System.out.println("start_point added! r, c : " + i + ", " + j);
							int []pos = {i, j};
							this.start_points.add(pos);
						}
						else if (token >= 'A' && token <= 'Z' && this.keys.contains(token + ('a' - 'A')) == false )
						{
							int []pos = {i, j};
							this.doors.add(pos);
						}
					}
				}
			}
		}

		public void game_start(){
			Queue <int[]> q = this.start_points;
			while (true){
				for (int i = 0; i < this.doors.size(); i++) {
					int []pos = doors.get(i);
					int r = pos[0];
					int c = pos[1];
					int token = this.map[r][c]; 
//					System.out.println("door checking! " + r + ", " + c);
					if (this.keys.contains(token + ('a' - 'A')) == true && this.visited[r][c] == 0)
					{
						q.add(pos);
//						System.out.println("now we can open! " + r + ", " + c);
					}
				}
				if (q.size() == 0)
					break;
				while (start_points.size() != 0){
					int []cur = q.poll();
					int cur_r = cur[0];
					int cur_c = cur[1];
					int token = this.map[cur_r][cur_c];
					if (this.visited[cur_r][cur_c] == 1)
						continue ;
					if (token >= 'a' && token <= 'z')
						this.keys.add(token);
					else if (token == '$')
					{
						this.papers++;
//						System.out.println("got paper in r, c : " + cur_r +", "+ cur_c);
					}
					this.visited[cur_r][cur_c] = 1;
					for (int i = 0; i < 4; i++) {
						int next_r = cur_r + dr[i];
						int next_c = cur_c + dc[i];
						if (next_r < 0 || next_r >= this.map_n || next_c < 0 || next_c >= this.map_m || this.visited[next_r][next_c] == 1)
							continue;
						int next_token = this.map[next_r][next_c];
						//cannot open
						int []next = {next_r, next_c};
						if (next_token >= 'A' && next_token <= 'Z' 
								&& this.keys.contains(next_token + ('a' - 'A')) == false)
						{
							this.doors.add(next);
//							System.out.println("closed door! r, c :"+ next_r + ", "+ next_c);
							continue;
						}
						if (next_token == '*')
							continue;
						q.add(next);
					}
				}
			}
		}

		public int get_papers(){
			return (this.papers);
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
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			int [][] _map = new int [n][m];
			for (int i = 0; i < n; i++) {
				String input = br.readLine();
				for (int j = 0; j < m; j++) {
					_map[i][j] = input.charAt(j);
				}
			}
			String _keys = br.readLine();
			Game g = new Game(_map, _keys);
			g.game_start();
			System.out.println(g.get_papers());
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
