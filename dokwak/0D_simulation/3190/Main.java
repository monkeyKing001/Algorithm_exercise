import java.util.*;
import java.io.*;


public class Main{
	//enum
	//empty = 0
	//dummy = 1
	//apple = 2
	static int n, m;
	static boolean game = true;
	static int dr[] = {0, 1, 0, -1};
	static int dc[] = {1, 0, -1, 0};
	static int head_r = 0;
	static int head_c = 0;
	static int cur_head_d = 0;
	static int cur_head_dr = dr[cur_head_d];
	static int cur_head_dc = dc[cur_head_d];
	static Queue<int[]>curve_info;
	static int map[][];
	static ArrayList<int[]> curve_point;
	static int cur_time = 0;
	static int tail_r = 0;
	static int tail_c = 0;
	static int cur_tail_d = 0;
	static int cur_tail_dr = dr[cur_tail_d];
	static int cur_tail_dc = dc[cur_tail_d];
	static int next_curve_point_r = -1;
	static int next_curve_point_c = -1;
	static int next_curve_point_d = 0;

	//move by one step
	
	public static void print_map(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == head_r && j == head_c)
					System.out.print(cur_time + " ");
				else
					System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	public static void move(){
		int next_head_r = head_r + cur_head_dr;
		int next_head_c = head_c + cur_head_dc;
		cur_time++;
		//out of map
		if (next_head_r < 0 || next_head_r >= n 
				|| next_head_c < 0 || next_head_c >= n 
				|| map[next_head_r][next_head_c] == 1)
		{
//			System.out.println("game over head r, c : " + head_r + ", " + head_c);
			game = false;
			return;
		}
		//ahead is apple
		//move only head
		if (map[next_head_r][next_head_c] == 2){//apple
			head_r = next_head_r;
			head_c = next_head_c;
			map[head_r][head_c] = 1;
//			System.out.println("ate apple r, c, time : " +head_r+", "+head_c+", "+cur_time);
			return ;
		}
		//remove_tail first
		//change direction
		if (next_curve_point_r == tail_r && next_curve_point_c == tail_c)
		{
			curve_point.remove(0);
			cur_tail_d += next_curve_point_d;
			if (cur_tail_d == -1)
				cur_tail_d = 3;
			if (cur_tail_d >= 4)
				cur_tail_d %= 4;
			if (curve_point.size () != 0){
				int curve_point_info[] = curve_point.get(0);
				int next_curve_r = curve_point_info[0];
				int next_curve_c = curve_point_info[1];
				int next_curve_d = curve_point_info[2];
				next_curve_point_r = next_curve_r;
				next_curve_point_c = next_curve_c;
				next_curve_point_d = next_curve_d;
//				System.out.println("$$$$ update dircetion info : "+next_curve_r + ", "+next_curve_c +", "+cur_tail_d);
			}
//			System.out.println("change tail r, c, dir : "+tail_r + ", "+tail_c +", "+cur_tail_d);
		}
		cur_tail_dr = dr[cur_tail_d];
		cur_tail_dc = dc[cur_tail_d];
		map[tail_r][tail_c] = 0;
		tail_r += cur_tail_dr;
		tail_c += cur_tail_dc;
		if (tail_r < 0 || tail_r >= n || tail_c < 0 || tail_c >= n){
//			System.out.println("game over tail == head r, c : " + tail_r + ", " + tail_c);
			game = false;
			return ;
		}
//		System.out.println("tail r, c, d : "+tail_r + ", "+tail_c +", "+next_curve_point_d);
		//move head
		head_r += cur_head_dr;
		head_c += cur_head_dc;
//		System.out.println("head r, c : " + head_r + ", "+ head_c);
		map[head_r][head_c] = 1;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		map = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = 0;
			}
		}
		st = new StringTokenizer(br.readLine()," ");
		curve_info = new LinkedList<>();
		curve_point = new ArrayList<>();
		int k = Integer.parseInt(st.nextToken());;
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			map[r][c] = 2;
		}
		map[0][0] = 1;
		st = new StringTokenizer(br.readLine()," ");
		int rotate = Integer.parseInt(st.nextToken());
		//rotate info
		for (int i = 0; i < rotate; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int curve_time = Integer.parseInt(st.nextToken());
			String dir_str = st.nextToken().toString();
			int dir = dir_str.charAt(0);
			int curve_info_entry[] = new int[2];
			curve_info_entry[0] = curve_time;
			curve_info_entry[1] = dir;
			curve_info.add(curve_info_entry);
		}
		while(game){
			int next_stop_time = Integer.MAX_VALUE;
			int next_curve_info[] = null;
			int next_d = 0;
			//read next_curve
			if (curve_info.size() != 0){
				next_curve_info = curve_info.poll();
				next_stop_time = next_curve_info[0];
				next_d = next_curve_info[1] == 'D' ? 1 : -1;
//				System.out.println("next stop time, dir : "+next_stop_time+", " + next_d);
			}
			//move on current direction
			while (game && cur_time < next_stop_time){
				move();
//				print_map();
			}
			//change dir (change head dir and add curve point)
			if (game && cur_time == next_stop_time){
//				System.out.println("change dir in time : " + cur_time);
				cur_head_d += next_d;
				if (cur_head_d >= 4)
					cur_head_d %= 4;
				else if (cur_head_d < 0)
					cur_head_d = 3;//error cur_head_d = 0; idiot
				cur_head_dr = dr[cur_head_d];
				cur_head_dc = dc[cur_head_d];
				//tail curve info updat
				int curve_point_entry[] = new int[3];
				curve_point_entry[0] = head_r;
				curve_point_entry[1] = head_c;
				curve_point_entry[2] = next_d;
				if (curve_point.size() == 0){
					next_curve_point_r = head_r;
					next_curve_point_c = head_c;
					next_curve_point_d = next_d;
//					System.out.println("no curve entry. next curve r, c : " + head_r + ", " + head_c);
				}
				curve_point.add(curve_point_entry);
//				System.out.println("### added curve_ point entry ###");
//				System.out.print("r, c, d : ");
//				System.out.print(curve_point.get(curve_point.size() - 1)[0]);
//				System.out.print(", ");
//				System.out.print(curve_point.get(curve_point.size() - 1)[1]);
//				System.out.print(", ");
//				System.out.print(curve_point.get(curve_point.size() - 1)[2]);
//				System.out.println();
			}
		}
		System.out.println(cur_time);
		return ;
	}
}
