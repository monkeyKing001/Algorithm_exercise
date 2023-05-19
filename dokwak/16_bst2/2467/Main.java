// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Main.java                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2023/05/13 19:10:50 by dokwak            #+#    #+#             //
//   Updated: 2023/05/13 19:10:52 by dokwak           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> arr ;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		arr = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		int l = 0, r = n - 1;
		int temp_l = 0, temp_r = n - 1;
		int sum = arr.get(temp_l) + arr.get(temp_r);
		sum = Integer.MAX_VALUE;
		while (temp_l < temp_r)
		{
			int temp_sum = arr.get(temp_l) + arr.get(temp_r);
			if (Math.abs(temp_sum) < Math.abs(sum))
			{
				l = temp_l;
				r = temp_r;
				sum = temp_sum;
			}
			if (temp_sum < 0)
				temp_l++;
			else if (temp_sum > 0)
				temp_r--;
			else if (temp_sum == 0)
				break;
		}
		System.out.println(arr.get(l) + " " + arr.get(r));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
