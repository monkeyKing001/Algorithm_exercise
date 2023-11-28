import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] upperCleaner = new int[2];
	static int[] lowerCleaner = new int[2];
	static int[][] buf;
	static int[][] map;
	static int T;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	static int sol = -1;
//	public static void printMap(){
//		System.out.println("##################################################################");
//		System.out.println("################       T : " + T + "         #####################");
//		System.out.println("##################################################################");
//		int count = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m ; j++){
//				System.out.print(map[i][j] + " ");
//				count += Integer.max(0, map[i][j]);
//			}
//			System.out.println();
//		}
//		sol = count;
//		System.out.println();
//	}

	public static void cleanDown(){
		int start_r = lowerCleaner[0];
		int start_c = lowerCleaner[1];
		int cur_r = start_r + 1;
		int cur_c = start_c;
		map[cur_r][cur_c] = 0;
		while (cur_r <= n - 2){
			map[cur_r][cur_c] = map[cur_r + 1][cur_c];
			cur_r++;
		}
		while (cur_c <= m - 2){
			map[cur_r][cur_c] = map[cur_r][cur_c + 1];
			cur_c++;
		}
		while (cur_r >= start_r + 1){
			map[cur_r][cur_c] = map[cur_r - 1][cur_c];
			cur_r--;
		}
		while (cur_c > start_c + 1){
			map[cur_r][cur_c] = map[cur_r][cur_c - 1];
			cur_c--;
		}
		map[cur_r][cur_c] = 0;
	}

	public static void cleanUp(){
		int start_r = upperCleaner[0];
		int start_c = upperCleaner[1];
		int cur_r = start_r;
		int cur_c = start_c;
		cur_r--;
		map[cur_r][cur_c] = 0;
		while (cur_r >= 1){
			map[cur_r][cur_c] = map[cur_r - 1][cur_c];
			cur_r--;
		}
		while (cur_c <= m - 2){
			map[cur_r][cur_c] = map[cur_r][cur_c + 1];
			cur_c++;
		}
		while (cur_r < start_r){
			map[cur_r][cur_c] = map[cur_r + 1][cur_c];
			cur_r++;
		}
		while (cur_c > start_c + 1){
			map[cur_r][cur_c] = map[cur_r][cur_c - 1];
			cur_c--;
		}
		map[cur_r][cur_c] = 0;
	}

	public static void diffuse(){
		makeBuf();
		move();
		cleanBuf();
	}

	public static void makeBuf(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				if(map[i][j] > 0){
					int div = map[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						int next_r = i + dr[k];
						int next_c = j + dc[k];
						if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && map[next_r][next_c] != -1)
						{
							map[i][j] -= div;
							buf[next_r][next_c] += div;
						}
					}
				}
			}
		}
	}
	public static void move(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				map[i][j] += buf[i][j];
			}
		}
	}
	public static void cleanBuf(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				buf[i][j] = 0;
			}
		}
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
		T = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		buf = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
				buf[i][j] = 0;
				if (map[i][j] == - 1){
					if (map[i - 1][j] == -1) {
						upperCleaner[0] = i-1;
						upperCleaner[1] = j;
						lowerCleaner[0] = i;
						lowerCleaner[1] = j;
					}
				}
			}
		}
		//printMap();
		while (T-- > 0){
			diffuse();
			//printMap();
			cleanUp();
			cleanDown();
			//printMap();
		}
		sol = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				sol += Integer.max(0, map[i][j]);
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


