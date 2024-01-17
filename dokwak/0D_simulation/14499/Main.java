import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> dice_front;
	static ArrayList<Integer> dice_side;
	static int bottom = 2;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int x, y, k = 0;
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		int r = x;
		int c = y;
		int map[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dice_front = new ArrayList<>();
		dice_side = new ArrayList<>();
		for (int i = 0; i < 4; i++) {
			dice_front.add(0);
			dice_side.add(0);
		}
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < k; i++) {
			int num = Integer.parseInt(st.nextToken());
			boolean movable = false;
			if (num == 1){
				if (c + 1 <= m - 1){
					c++;
					movable = true;
					int pop = dice_side.remove(0);
					dice_side.add(pop);
					dice_front.set(0, dice_side.get(0));
					dice_front.set(2, dice_side.get(2));
				}
			}
			else if (num == 2){
				if (c - 1 >= 0){
					c--;
					movable = true;
					int pop = dice_side.remove(3);
					dice_side.add(0, pop);
					dice_front.set(0, dice_side.get(0));
					dice_front.set(2, dice_side.get(2));
				}
			}
			else if (num == 3){
				if (r - 1 >= 0){
					r--;
					movable = true;
					int pop = dice_front.remove(0);
					dice_front.add(pop);
					dice_side.set(0, dice_front.get(0));
					dice_side.set(2, dice_front.get(2));
				}
			}
			else if (num == 4){
				if (r + 1 <= n - 1){
					r++;
					movable = true;
					int pop = dice_front.remove(3);
					dice_front.add(0, pop);
					dice_side.set(0, dice_front.get(0));
					dice_side.set(2, dice_front.get(2));
				}
			}
			if (movable){
				int floor = map[r][c];
				if (floor == 0){
					map[r][c] = dice_front.get(bottom);
				}
				else if (floor != 0){
					map[r][c] = 0;
					dice_front.set(bottom, floor);
					dice_side.set(bottom, floor);
				}
//				System.out.println("change side : " + dice_side.toString());
//				System.out.println("change front : " + dice_front.toString());
//				System.out.println("map");
//				for (int ii = 0; ii < n; ii++) {
//					for (int jj = 0; jj < m ; jj++){
//						System.out.print(map[ii][jj] + " ");
//					}
//					System.out.println();
//				}
////				System.out.println("position x, y : " + x + ", "+ y);
				System.out.println(dice_front.get(0));
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
