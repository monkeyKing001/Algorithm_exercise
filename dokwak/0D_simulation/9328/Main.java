import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []dr = {0, 1, -1, 0};
	static int []dc = {1, 0, 0, -1};
	public static class game{
		public 
			int [][] map;
			int [][] visited;
			ArrayList<int[]> door;
			Set<Integer> key;
			ArrayList<int[]> start_point;
			Set<int[]> paper;

		game(int[][] _map, String keys){
			this.map = _map;
			this.key = new HashSet<>();
			this.paper = new HashSet<>();
			for (int i = 0; i < keys.length(); i++) {
				key.add((int)keys.charAt(i));
			}
		}

		public void map_read(){
			this.door = new ArrayList<>();
			this.start_point = new ArrayList<>();
			this.visited = new int[this.map.length][this.map[0].length];
			for (int i = 0; i < this.map.length; i++) {
				for (int j = 0; j < map[i].length; j++) {
					visited[i][j] = 0;
					if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					{
						int token = this.map[i][j];
						int [] point = new int[2];
						point[0] = i;
						point[1] = j;
						if (token == '.')
							start_point.add(point);
						if (token >= 'a' && token <= 'z')
						{
							this.key.add(map[i][j]);
							this.map[i][j] = '.';
							start_point.add(point);
						}
						if (token >= 'A' && token <= 'Z')
							this.door.add(point);
						if (token == '$')
						{
							this.paper.add(point);
							this.map[i][j] = '.';
							start_point.add(point);
						}
					}
				}
			}
		}

		public void print_map(){
			for (int i = 0; i < this.map.length; i++) {
				for (int j = 0; j < this.map[i].length; j++) {
					System.out.print((char)this.map[i][j]);
				}
				System.out.println();
			}
		}

		public void game_start(){
			//start
			Queue<int[]> q = new LinkedList<>();
			for (int i = 0; i < this.start_point.size(); i++) {
				q.add(start_point.get(i));
			}
			//traverse bfs
			traverse(q);
			while (true){
				for (int d_i = 0; d_i < this.door.size(); d_i++) {
					int []door_pos = this.door.get(d_i);
					int door_r = door_pos[0];
					int door_c = door_pos[1];
					int door_num = this.map[door_r][door_c];
					if (this.visited[door_r][door_c] == 0 && this.key.contains(door_num + ('a' - 'A')) == true){
						q.add(door_pos);
					}
				}
				if (q.size() == 0)
					break;
				else traverse(q);
			}
		}

		public void traverse(Queue <int[]> q){
			//traverse
			while (q.size() != 0)
			{
				int [] cur = q.poll();
				int cur_r = cur[0];
				int cur_c = cur[1];
				int token = this.map[cur_r][cur_c];
				if (this.visited[cur_r][cur_c] != 0)
					continue ;
				//cannot visit
				//cannot open door
				if (this.map[cur_r][cur_c] >= 'A' && this.map[cur_r][cur_c] <= 'Z')
				{
					//cannot open
					if (this.key.contains(token + ('a' - 'A')) == false)
					{
						this.door.add(cur);
						continue ;
					}
				}
				
				//can visit
				//road, open door
				//key
				else if (this.map[cur_r][cur_c] >= 'a' && this.map[cur_r][cur_c] <= 'z')
					this.key.add(token);
				//paper
				else if (this.map[cur_r][cur_c] == '$')
					this.paper.add(cur);
				//visited marking
				this.map[cur_r][cur_c] = '.';
				this.visited[cur_r][cur_c] = 1;
				//next move
				for (int i = 0; i < 4; i++) {
					int next_r = cur_r + dr[i];
					int next_c = cur_c + dc[i];
					if (next_r > -1 && next_r < n && next_c > -1 && next_c < m && this.visited[next_r][next_c] == 0 && this.map[next_r][next_c] != '*'){
						int []next = new int[2];
						next[0] = next_r;
						next[1] = next_c;
						q.add(next);
					}
				}

			}
		}

		public int sol(){
			return (this.paper.size());
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
			int [][]map = new int[n][m];
			for (int i = 0; i < n; i++) {
				String temp = br.readLine();	
				for (int j = 0; j < m; j++) {
					map[i][j] = temp.charAt(j);
				}
			}
			String keys = br.readLine();
			game my_game = new game(map, keys);
			my_game.map_read();
			my_game.game_start();
//			my_game.print_map();
			System.out.println(my_game.sol());
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
