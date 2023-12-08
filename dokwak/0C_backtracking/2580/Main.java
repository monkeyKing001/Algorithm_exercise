import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static Set<Integer> set[] = new HashSet[9];
	static boolean finished = false;
	public static void rec(int[][] map, int curIdx){
		if (finished)
			return;
		if (curIdx == 81){
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9 ; j++){
					System.out.print(map[i][j] + " ");
				}
				System.out.println();
			}
			finished = true;
			return ;
		}
		int curR = curIdx / 9;
		int curC = curIdx % 9;
		if (map[curR][curC] != 0)
			rec(map, curIdx + 1);
		else{
			for (int tryNum = 1; tryNum <= 9; tryNum++) {
				//row check
				//col check
				boolean possible = true;
				//set check
				int setIdx = 0;
				setIdx += curC / 3; 
				setIdx += 3 * (curR / 3);
				if (set[setIdx].contains(tryNum))
					continue;
				for (int i = 0; i < 9; i++) {
					if (map[i][curC] == tryNum || map[curR][i] == tryNum){
						possible = false;
						break;
					}
				}
				if (!possible)
					continue;
				//if ok, try
				//add map
				//add set
				map[curR][curC] = tryNum;
				set[setIdx].add(tryNum);
				rec(map, curIdx + 1);
				//backtrack
				//remove map
				//remove set
				map[curR][curC] = 0;
				set[setIdx].remove(tryNum);
					
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int [][] map = new int[9][9];
		for (int i = 0; i < 9; i++) {
			set[i] = new HashSet<>();
		}
		for (int i = 0; i < 9; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < 9 ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] != 0) {
					int setIdx = 0;
					setIdx += j / 3; 
					setIdx += 3 * (i / 3);
					set[setIdx].add(map[i][j]);
				}
			}
		}
		rec(map, 0);
		//input
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


