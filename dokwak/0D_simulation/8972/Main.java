import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
	static int dc[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
	static int jongSu[] = {0, 0};
	static ArrayList<int []> mad_adu;
	static int map[][];
	static boolean finish = false;
	static HashMap<String, ArrayList<Integer>> buffer;

	public static int getClosestDir(int R[]){
		int dir = -1;
		int cost = 1000000; 
		int cur_r = R[0];
		int cur_c = R[1];
		for (int i = 1; i < 10; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			int next_cost = Math.abs(jongSu[0] - next_r) + Math.abs(jongSu[1] - next_c);
			if (next_cost < cost)
			{
				dir = i;
				cost = next_cost;
			}
		}
		return (dir);
	}

	public static void jongSuMove(int dir){
		int cur_r = jongSu[0];
		int cur_c = jongSu[1];
		int next_r = cur_r + dr[dir];
		int next_c = cur_c + dc[dir];
		if (map[next_r][next_c] == 'R')
		{
			finish = true;
			return ;
		}
		map[cur_r][cur_c] = '.';
		map[next_r][next_c] = 'I';
		jongSu[0] = next_r;
		jongSu[1] = next_c;
	}

	public static void moveNBombAudBuffer(){
		Iterator<Map.Entry<String, ArrayList<Integer>>> it = buffer.entrySet().iterator();
		//move first
		while (it.hasNext()){
			String key = it.next().getKey();
			ArrayList<Integer> value = buffer.get(key);
			StringTokenizer st = new StringTokenizer(key,",");
			if (value.size() == 1){
				int next_r = Integer.parseInt(st.nextToken());
				int next_c = Integer.parseInt(st.nextToken());
				int adu_i = value.get(0);
				int cur_r = mad_adu.get(adu_i)[0];
				int cur_c = mad_adu.get(adu_i)[1];
				String check_key = Integer.toString(cur_r) + "," + Integer.toString(cur_c);
//				System.out.println(check_key + " can move to " + key);
				if (buffer.containsKey(check_key) == false || (buffer.containsKey(check_key) == true && buffer.get(check_key).size() != 1))
				{
					map[cur_r][cur_c] = '.';
				}
				map[next_r][next_c] = 'R';
				mad_adu.get(adu_i)[0] = next_r;
				mad_adu.get(adu_i)[1] = next_c;
			}
		}
		//bomb after
		it = buffer.entrySet().iterator();
		ArrayList<int []> remove_adu = new ArrayList<>();
		while (it.hasNext()){
			String key = it.next().getKey();
			ArrayList<Integer> value = buffer.get(key);
			if (value.size() != 1){
				//destroy all the aduino
//				System.out.println(key + " position will be blow up.");
				for (int i = 0; i < value.size(); i++) {
					int adu_i = value.get(i);
					int []adu = mad_adu.get(adu_i);
					int cur_r = adu[0];
					int cur_c = adu[1];
					String check_key = Integer.toString(cur_r) + "," + Integer.toString(cur_c);
					if (buffer.containsKey(check_key) == false || (buffer.containsKey(check_key) == true && buffer.get(check_key).size() != 1))
					{
						map[cur_r][cur_c] = '.';
					}
					remove_adu.add(adu);
				}
//				System.out.println("bomb adu num : " + value.size());
				value.clear();
			}
		}
		mad_adu.removeAll(remove_adu);
		buffer.clear();
	}

	public static void aduMove(){
		if (finish == true)
			return;
		for (int i = 0; i < mad_adu.size(); i++) {
			int adu[] = mad_adu.get(i);
			int dir = getClosestDir(adu);
			int cur_r = adu[0];
			int cur_c = adu[1];
//			System.out.println("cur_r, cur_c  : " + cur_r + ", " + cur_c);
//			System.out.println("close move is : " + dir);
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			if (map[next_r][next_c] == 'I')
			{
				finish = true;
				return ;
			}
			String key = Integer.toString(next_r) + ","+ Integer.toString(next_c);
			if (buffer.containsKey(key) == true)
			{
				ArrayList<Integer> value = buffer.get(key);
				value.add(i);
				//buffer.put(key, value);
			}
			else{
				ArrayList<Integer> value = new ArrayList<>();
				value.add(i);
				buffer.put(key, value);
			}
		}
		moveNBombAudBuffer();
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int [n + 1][m + 1];
		mad_adu = new ArrayList<>();
		buffer = new HashMap<>();
		for (int i = 0; i < n; i++) {
			String line = br.readLine().toString();
			for (int j = 0; j < m; j++) {
				map[i][j] = line.charAt(j);
				if (map[i][j] == 'I'){
					jongSu[0] = i;
					jongSu[1] = j;
				}
				else if (map[i][j] == 'R'){
					int adu[] = new int[2];
					adu[0] = i;
					adu[1] = j;
					mad_adu.add(adu);
				}
			}
		}
		String move_line = br.readLine().toString(); 
		for (int i = 0; i < move_line.length() && finish == false; i++) {
			int move = move_line.charAt(i) - '0';
//			System.out.println("moving dir : " + move);
			jongSuMove(move);
			aduMove();
			if (finish == true){
				System.out.println("kraj " + (i + 1));
				return;
			}
//			System.out.println("#######    after moving map    #######");
//			printMap();
		}
		printMap();
		bw.write(sb.toString());
		bw.flush();
		return ;
	}

	public static void printMap(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print((char)map[i][j]);
			}
			System.out.println();
		}
	}

}
