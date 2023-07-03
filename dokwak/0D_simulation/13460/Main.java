import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] R = new int[2];
	static int[] B = new int[2];
	static int[][] map = new int[10][10];
	static int sol = -1;
	public static class nowMap{
		public
			int stage;
			int [][]map;
			int direction;
			int prev_direction;
			int end; //0 -> keep going 1 -> found answer, -1 -> gameover

		public nowMap(){
			this.stage = 0;
			this.map = null;
			this.direction = -1;
			this.prev_direction = -1;
			this.end = 0;
		}
		public nowMap(nowMap o)
		{
			this.stage = o.stage;
			this.map = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = o.map[i][j];
				}
			}
			this.direction = o.direction;
			this.prev_direction = o.prev_direction;
			this.end = o.end;
		}
		public nowMap(int _stage, int [][]_map, int _prev_direction, int _direction, int _end){
			this.stage = _stage;
			this.map = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = _map[i][j];
				}
			}
			this.direction = _direction;
			this.prev_direction = _prev_direction;
			this.end = _end;
		}
		public void printMap(){
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (this.map[i][j] == 0)
						System.out.print('.');
					else if (this.map[i][j] == 1)
						System.out.print('R');
					else if (this.map[i][j] == 2)
						System.out.print('B');
					else if (this.map[i][j] == 3)
						System.out.print('O');
					else if (this.map[i][j] == -1)
						System.out.print('#');
				}
				System.out.println();
			}
		}
		public int[] findR(){
			int []cur_r = new int[2];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (this.map[i][j] == 1)
					{
						cur_r[0] = i;
						cur_r[1] = j;
						return (cur_r);
					}
				}
			}
			//not foune
			cur_r[0] = -1;
			cur_r[1] = -1;
			return (cur_r);
		}
		public int[] findB(){
			int []cur_b = new int[2];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (this.map[i][j] == 2)
					{
						cur_b[0] = i;
						cur_b[1] = j;
						return (cur_b);
					}
				}
			}
			cur_b[0] = -1;
			cur_b[1] = -1;
			return (cur_b);
		}
	}
	//move_dir => {0 : up,  1: left, 2 : right, 3 : down}

	public static int up(nowMap now){
		int[][] cur_map = now.map;
		int[] r_pos = now.findR();
		int[] b_pos = now.findB();
		int []first = r_pos;
		int []second = b_pos;
		int count = 0;
		if (r_pos[1] == b_pos[1] && b_pos[0] < r_pos[0])
		{
			first = b_pos;
			second = r_pos;
		}
		//first ball rolling
		while (first[0] > 0 && cur_map[first[0] - 1][first[1]] == 0)
		{
			cur_map[first[0] - 1][first[1]] = cur_map[first[0]][first[1]];
			cur_map[first[0]][first[1]] = 0;
			first[0]--;
			count++;
		}
		//first hole in
		if (cur_map[first[0] - 1][first[1]] == 3)
		{
			cur_map[first[0]][first[1]] = 0;
			count++;
		}
		//second ball rolling
		while (second[0] > 0 && cur_map[second[0] - 1][second[1]] == 0)
		{
			cur_map[second[0] - 1][second[1]] = cur_map[second[0]][second[1]];
			cur_map[second[0]][second[1]] = 0;
			second[0]--;
			count++;
		}
		//second hole in
		if (cur_map[second[0] - 1][second[1]] == 3)
		{
			cur_map[second[0]][second[1]] = 0;
			count++;
		}
		//RED HOLE in
		if (now.findR()[0] == -1)
			now.end = 1;
		//BLUE HOLE in
		if (now.findB()[0] == -1)
			now.end = -1;
		return (count);
	}
	public static int left(nowMap now){
		int[][] cur_map = now.map;
		int[] r_pos = now.findR();
		int[] b_pos = now.findB();
		int []first = r_pos;
		int []second = b_pos;
		int count = 0;
		//on same row and blue is first move
		if (r_pos[0] == b_pos[0] && b_pos[1] < r_pos[1])
		{
			first = b_pos;
			second = r_pos;
		}
		//first ball rolling
		while (first[1] > 0 && cur_map[first[0]][first[1] - 1] == 0)
		{
			cur_map[first[0]][first[1] - 1] = cur_map[first[0]][first[1]];
			cur_map[first[0]][first[1]] = 0;
			first[1]--;
			count++;
		}
		//hole in
		if (cur_map[first[0]][first[1] - 1] == 3)
		{
			cur_map[first[0]][first[1]] = 0;
			count++;
		}
		//second ball rolling
		while (second[1] > 0 && cur_map[second[0]][second[1] - 1] == 0)
		{
			cur_map[second[0]][second[1] - 1] = cur_map[second[0]][second[1]];
			cur_map[second[0]][second[1]] = 0;
			second[1]--;
			count++;
		}
		//second hole in
		if (cur_map[second[0]][second[1] - 1] == 3)
		{
			cur_map[second[0]][second[1]] = 0;
			count++;
		}
		//RED HOLE in
		if (now.findR()[0] == -1)
			now.end = 1;
		//BLUE HOLE in
		if (now.findB()[0] == -1)
			now.end = -1;
		return (count);
	}
	public static int right(nowMap now){
		int[][] cur_map = now.map;
		int[] r_pos = now.findR();
		int[] b_pos = now.findB();
		int []first = r_pos;
		int []second = b_pos;
		int count = 0;
		//on same row and blue is first move
		if (r_pos[0] == b_pos[0] && b_pos[1] > r_pos[1])
		{
			first = b_pos;
			second = r_pos;
		}
		//first ball rolling
		while (first[1] < m - 1 && cur_map[first[0]][first[1] + 1] == 0)
		{
			cur_map[first[0]][first[1] + 1] = cur_map[first[0]][first[1]];
			cur_map[first[0]][first[1]] = 0;
			first[1]++;
			count++;
		}
		//hole in
		if (cur_map[first[0]][first[1] + 1] == 3)
		{
			cur_map[first[0]][first[1]] = 0;
			count++;
		}
		//second ball rolling
		while (second[1] < m - 1 && cur_map[second[0]][second[1] + 1] == 0)
		{
			cur_map[second[0]][second[1] + 1] = cur_map[second[0]][second[1]];
			cur_map[second[0]][second[1]] = 0;
			second[1]++;
			count++;
		}
		//second hole in
		if (cur_map[second[0]][second[1] + 1] == 3)
		{
			cur_map[second[0]][second[1]] = 0;
			count++;
		}
		//RED HOLE in
		if (now.findR()[0] == -1)
			now.end = 1;
		//BLUE HOLE in
		if (now.findB()[0] == -1)
			now.end = -1;
		return (count);
	}
	public static int down(nowMap now){
		int[][] cur_map = now.map;
		int[] r_pos = now.findR();
		int[] b_pos = now.findB();
		int []first = r_pos;
		int []second = b_pos;
		int count = 0;
		if (r_pos[1] == b_pos[1] && b_pos[0] > r_pos[0])
		{
			first = b_pos;
			second = r_pos;
		}
		//first ball rolling
		while (first[0] < n - 1 && cur_map[first[0] + 1][first[1]] == 0)
		{
			cur_map[first[0] + 1][first[1]] = cur_map[first[0]][first[1]];
			cur_map[first[0]][first[1]] = 0;
			first[0]++;
			count++;
		}
		//hole in
		if (cur_map[first[0] + 1][first[1]] == 3)
		{
			cur_map[first[0]][first[1]] = 0;
			count++;
		}
		//second ball rolling
		while (second[0] < n - 1 && cur_map[second[0] + 1][second[1]] == 0)
		{
			cur_map[second[0] + 1][second[1]] = cur_map[second[0]][second[1]];
			cur_map[second[0]][second[1]] = 0;
			second[0]++;
			count++;
		}
		//second hole in
		if (cur_map[second[0] + 1][second[1]] == 3)
		{
			cur_map[second[0]][second[1]] = 0;
			count++;
		}
		//RED HOLE in
		if (now.findR()[0] == -1)
			now.end = 1;
		//BLUE HOLE in
		if (now.findB()[0] == -1)
			now.end = -1;
		return (count);
	}

	public static int move(nowMap now)
	{
		int move_count = 0;
		int now_dir = now.direction; 
		switch (now_dir){
			case 0:
				move_count = up(now);
				now.prev_direction = 0;
				break;
			case 1:
				move_count = left(now);
				now.prev_direction = 1;
				break;
			case 2:
				move_count = right(now);
				now.prev_direction = 2;
				break;
			case 3:
				move_count = down(now);
				now.prev_direction = 3;
				break;
			default:
				break;
		}
		now.stage++;
		return (move_count);
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
		Queue <nowMap> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			String buf = br.readLine();
			for (int j = 0; j < m; j++) {
				if (buf.charAt(j) == '#')
					map[i][j] = -1;
				else if (buf.charAt(j) == '.')
					map[i][j] = 0;
				else if (buf.charAt(j) == 'R')
					map[i][j] = 1;
				else if (buf.charAt(j) == 'B')
					map[i][j] = 2;
				else if (buf.charAt(j) == 'O')
					map[i][j] = 3;
			}
		}
		for (int i = 0; i < 4; i++) {
			
			nowMap start = new nowMap(0, map, -1, i, 0);
			q.add(start);
		}
		while (q.size() != 0)
		{
			nowMap now = q.poll();
//			System.out.println("@@@@@@@    moving : " + now.direction + "      @@@@@@@");
//			System.out.println("#######    before moving stage : " + now.stage + "   ##########");
//			now.printMap();
			//moving
			if (now.stage > 9 || move(now) == 0)
			{
//				System.out.println("no more moving");
				continue ;
			}
//			System.out.println("#######    after moving stage : " + now.stage + "   ##########");
//			now.printMap();
			//gameover
			if (now.end == -1)
				continue;
			if (now.end == 1)
			{
				sol = now.stage;
				q.clear();
				break;
			}
			for (int d_i = 0; d_i < 4; d_i++) {
				if (now.direction == d_i || now.prev_direction + d_i == 3)
					continue;
				else{
					nowMap nextMap = new nowMap(now);
					nextMap.prev_direction = nextMap.direction;
					nextMap.direction = d_i;
					q.add(nextMap);
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


