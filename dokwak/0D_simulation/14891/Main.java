import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int left = -2;
	static int right = 2;
	static int score = 0;
	static int gear_head[];
	static int moved[];
	static int gears[][];
	
	public static void get_score(){
		for (int i = 0; i < 4; i++) {
			int offset = 1 << i;
			if(gears[i][gear_head[i]] == 1)
				score += offset;
		}
	}

	public static void rotate(int gear_num, int dir){
		if (gear_num < 1 || gear_num > 4)
			return;
		int gear_idx = gear_num - 1;
		if (moved[gear_idx] == 1)
			return;
		//move check
		moved[gear_idx] = 1;

		//chain moving
		int gear_right_tooth = gear_head[gear_idx] + 2; 
		gear_right_tooth %= 8;

		//right rotate
		if (gear_idx != 3 && moved[gear_idx + 1] == 0)
		{
			int next_gear_left_tooth = gear_head[gear_idx + 1] - 2;
			if (next_gear_left_tooth < 0)
				next_gear_left_tooth += 8;
			if (gears[gear_idx][gear_right_tooth] != gears[gear_idx + 1][next_gear_left_tooth])
				rotate(gear_num + 1, dir * -1);
		}

		//left rotate
		int gear_left_tooth = gear_head[gear_idx] - 2;
		if (gear_left_tooth < 0)
			gear_left_tooth += 8;
		if (gear_idx != 0 && moved[gear_idx - 1] == 0){
			int prev_gear_right_tooth = gear_head[gear_idx - 1] + 2;
			prev_gear_right_tooth %= 8;
			if (gears[gear_idx][gear_left_tooth] != gears[gear_idx - 1][prev_gear_right_tooth])
				rotate(gear_num - 1, dir * -1);
		}

		//move gear
		gear_head[gear_idx] += dir * -1;
		if (gear_head[gear_idx] < 0)
			gear_head[gear_idx] += 8;
		gear_head[gear_idx] %= 8;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input gear information
		gears = new int [4][8];
		gear_head = new int[4];
		moved = new int[4];
		for (int i = 0; i < 4; i++) {
			String gear_info = br.readLine().toString();
			for (int j = 0; j < 8; j++) {
				gears[i][j] = gear_info.charAt(j) - '0';
			}
			gear_head[i] = 0;
		}
		//input rotate information
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int gear_num = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			for (int moved_i = 0; moved_i < 4; moved_i++) {
				moved[moved_i] = 0;
			}
			// 1 -> clock wise 
			// -1 -> counter clock wise
			rotate(gear_num, dir);
		}
		get_score();
		System.out.println(score);
		return ;
	}
}
