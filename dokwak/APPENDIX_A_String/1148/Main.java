import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//		StringBuilder sb = new StringBuilder();
//		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		String dictExit = "-";
		String puzzleExit = "#";

		//input
		ArrayList<String> dict = new ArrayList<>();
		String str = st.nextToken();
		while (str.compareTo(dictExit) != 0){
			dict.add(str);
			str = br.readLine();
		}
		int [][] dict_arr = new int[dict.size()][26];
		for (int i = 0; i < dict.size(); i++) {
			String dicStr = dict.get(i);
			for (int str_i = 0; str_i < dicStr.length(); str_i++) {
				int idx = dicStr.charAt(str_i) - 'A';
				dict_arr[i][idx]++;
			}
		}
		str = br.readLine();
		ArrayList<String> puzBase = new ArrayList<>();
		while (str.compareTo(puzzleExit) != 0){
			String puzzleBase = str;
			//next puzzle
			puzBase.add(puzzleBase);
			str = br.readLine();
		}
		int [][] base_arr = new int[puzBase.size()][26];
		int [][] base_statistic = new int[puzBase.size()][26];
		for (int i = 0; i < puzBase.size(); i++) {
			String puzzleBase = puzBase.get(i);
			for (int str_i = 0; str_i < puzzleBase.length(); str_i++) {
				int idx = puzzleBase.charAt(str_i) - 'A';
				base_arr[i][idx]++;
			}
		}
		for (int i = 0; i < base_arr.length; i++) {
//			sb.append("base : " + puzBase.get(i));
//			sb.append("\n");
			for (int dict_i = 0; dict_i < dict_arr.length; dict_i++) {
				boolean made = true;
				for (int spell_i = 0; spell_i < 26; spell_i++) {
					if (dict_arr[dict_i][spell_i] > base_arr[i][spell_i]) {
//						sb.append("dict str : " + dict.get(dict_i));
//						sb.append(" less char : " + (char)(spell_i + 'A'));
//						sb.append("\n");
						made = false;
						break;
					}
				}
				//the current puzzle base can make the word.
				if (made){
//					sb.append("dict possible : " + dict.get(dict_i));
//					sb.append("\n");
					for (int spell_i = 0; spell_i < 26; spell_i++) {
						if (dict_arr[dict_i][spell_i] > 0) {
							base_statistic[i][spell_i]++;
						}
					}
				}
			}
		}
		int[][] base_sol = new int[base_statistic.length][2];//min, max
		ArrayList<Character> maxSol[] = new ArrayList[base_statistic.length];
		ArrayList<Character> minSol[] = new ArrayList[base_statistic.length];
		for (int i = 0; i < base_statistic.length; i++) {
			maxSol[i] = new ArrayList<>();
			minSol[i] = new ArrayList<>();
//			sb.append("base : " + puzBase.get(i));
//			sb.append("\n");
			int min = Integer.MAX_VALUE;
			int max = Integer.MIN_VALUE;
			for (int j = 0; j < 26 ; j++){
				if (base_arr[i][j] != 0) {
//					sb.append((char)(j + 'A')  + " : " + base_statistic[i][j] + " ");
					if (base_statistic[i][j] < min){
						min = base_statistic[i][j];
					}
					if (base_statistic[i][j] > max){
						max = base_statistic[i][j];
					}
				}
			}
			base_sol[i][0] = min;
			base_sol[i][1] = max;
//			sb.append("\n");
			for (int j = 0; j < 26 ; j++){
				if (base_arr[i][j] != 0) {
					if (base_statistic[i][j] == min) {
						minSol[i].add((char)(j + 'A'));
					}
					if (base_statistic[i][j] == max) {
						maxSol[i].add((char)(j + 'A'));
					}
				}
			}
			for (int min_i = 0; min_i < minSol[i].size(); min_i++) {
				System.out.print(minSol[i].get(min_i));
			}
			System.out.print(" ");
			System.out.print(base_sol[i][0]);
			System.out.print(" ");
			for (int max_i = 0; max_i < maxSol[i].size(); max_i++) {
				System.out.print(maxSol[i].get(max_i));
			}
			System.out.print(" ");
			System.out.print(base_sol[i][1]);
			System.out.println("");
//			sb.append("min : " + minSol[i]);
//			sb.append("\n");
//			sb.append("max : " + maxSol[i]);
//			sb.append("\n");
		}
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}
