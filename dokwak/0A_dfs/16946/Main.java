// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Main.java                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/05/28 20:57:02 by dokwak            #+#    #+#             //
//   Updated: 2023/05/30 02:06:31 by dokwak           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int [][] map = new int[1001][1001];
	static int [] p = new int[1000001];
	static int [] mem_num = new int[1000001];
	static int[] dr = {1, 0, -1, 0};
	static int[] dc = {0, -1, 0, 1};
	public static int find(int r, int c)
	{
		int index = r * m + c;
		if (p[index] == -1)
			return (index);
		int p_r = p[index] / m, p_c = p[index] % m;
		p[index] = find(p_r, p_c);
		return p[index];
	}

	public static void union(int r_1, int c_1, int r_2, int c_2)
	{
		int g1 = find(r_1, c_1);
		int g2 = find(r_2, c_2);
		if (g1 == g2)
			return;
		if (g2 < g1)
		{
			int temp = g1;
			g1 = g2;
			g2 = temp;
		}
		p[g2] = g1;
		mem_num[g1] += mem_num[g2];
		mem_num[g2] = 0;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		Queue<int[]> q_one = new LinkedList<>();
		PriorityQueue<int[]> q_zero = new PriorityQueue<int[]>(new Comparator<int []>(){
			@Override
			public int compare(int []e1, int []e2){
				return (Integer.compare(e1[0] * e1[1], e2[0]* e2[1]));
			}
		});

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		//init p, mem_num;
		for (int i = 0; i < n * m; i++) {
			p[i] = -1;
			mem_num[i] = 1;
		}
		//map read
		for (int i = 0; i < n; i++) {
			String temp = br.readLine().toString();
			for (int j = 0; j < temp.length(); j++) {
				char temp_chr = temp.charAt(j);
				map[i][j] = temp_chr == '0' ? 0 : 1;
				int []temp_arr = new int[2];
				//add 1 in que_one
				temp_arr[0] = i;
				temp_arr[1] = j;
				if (map[i][j] == 1)
					q_one.add(temp_arr);
				//add 0 coordination in que_z
				else
					q_zero.add(temp_arr);
			}
		}
		//bfs union find
		//map test
		//parent, mem_num init
		while (q_zero.size() != 0)
		{
			int cur_r = q_zero.peek()[0];
			int cur_c = q_zero.peek()[1];
			int find_cur_p = find(cur_r, cur_c);
			q_zero.poll();
			if (find(cur_r, cur_c) != find_cur_p)
				continue;
//			System.out.println("start bfs. c_r, c_c : " +cur_r+", "+cur_c);
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				if (next_r >= 0 && next_r < n && 
						next_c >= 0 && next_c < m && 
						map[next_r][next_c] == 0 &&
						find_cur_p != find(next_r, next_c))
				{
					union(cur_r, cur_c, next_r, next_c);
					int []next_cor = new int[2];
					next_cor[0] = next_r;
					next_cor[1] = next_c;
					q_zero.add(next_cor);
				}
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				System.out.print(find(i, j) + "\t");
//			}
//			System.out.println();
//		}
//		for (int i = 0; i < n * m; i++) {
//			if (i % 10 == 0)
//				System.out.println();
//			System.out.print(mem_num[i] + "\t");
//		}
//		System.out.println();
		while (q_one.size() != 0)
		{
			int cur_r = q_one.peek()[0];
			int cur_c = q_one.peek()[1];
			q_one.poll();
//			System.out.println("updating r, c : " +cur_r+", "+cur_c);
			Set<Integer> s = new HashSet<>();
			for (int i = 0; i < 4; i++) {
				int adj_r = cur_r + dr[i];
				int adj_c = cur_c + dc[i];
				if (adj_r >= 0 && adj_r < n && adj_c >= 0 && adj_c < m && map[adj_r][adj_c] == 0)
					s.add(find(adj_r, adj_c));
			}
			Iterator<Integer> it = s.iterator();
			while (it.hasNext())
			{
				int index = it.next();
				map[cur_r][cur_c] += mem_num[index];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sb.append(Integer.toString(map[i][j] % 10));
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
