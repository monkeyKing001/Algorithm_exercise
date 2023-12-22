import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int map[][] = new int[n + 1][n + 1];
		ArrayList<int[]> chicken = new ArrayList<>();
		ArrayList<int[]> house = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1){
					int [] h = new int[2];
					h[0] = i;
					h[1] = j;
					house.add(h);
				}
				else if (map[i][j] == 2){
					int [] c = new int[2];
					c[0] = i;
					c[1] = j;
					chicken.add(c);
				}
			}
		}
		int dp[][] = new int[house.size()][chicken.size()];
		for (int i = 0; i < house.size(); i++) {
			int [] cur_h = house.get(i);
			int h_r = cur_h[0];
			int h_c = cur_h[1];
			for (int j = 0; j < chicken.size() ; j++){
				int[] cur_c = chicken.get(j);
				int chi_r = cur_c[0];
				int chi_c = cur_c[1];
				dp[i][j] = Math.abs(h_r - chi_r) + Math.abs(h_c - chi_c);
			}
		}
		int bit = 0;
		int maxBit = 1 << chicken.size();
		maxBit--;
		int sol = Integer.MAX_VALUE;
		while (bit++ <= maxBit){
			ArrayList<Integer> hitsChick = new ArrayList<>();
			for (int shift = 0; shift < chicken.size(); shift++) {
				if ((1 & (bit >> shift)) != 0){//hit
					hitsChick.add(shift);
				}
			}
			if (hitsChick.size() == m){
				int tempTotalDistance = 0;
				for (int h_i = 0; h_i < house.size(); h_i++) {
					int minDis = Integer.MAX_VALUE;
					int h_r = house.get(h_i)[0];
					int h_c = house.get(h_i)[1];
					for (int c_i = 0; c_i < hitsChick.size(); c_i++){
						int chick_idx = hitsChick.get(c_i);
						int chi[] = chicken.get(chick_idx);
						int chi_r = chi[0];
						int chi_c = chi[1];
						int temp_distance = Math.abs(h_r - chi_r) + Math.abs(h_c - chi_c); 
						minDis = Integer.min(minDis, temp_distance);
					}
					tempTotalDistance += minDis;
				}
				sol = Integer.min(tempTotalDistance, sol);
//				System.out.println(sol);
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


