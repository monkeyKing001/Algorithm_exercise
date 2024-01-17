import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<int[][]> threeByThree = new ArrayList<>();
	static ArrayList<int[][]> twoBytwo = new ArrayList<>();
	static ArrayList<int[][]> fourByfour = new ArrayList<>();
	static ArrayList<ArrayList<int[][]>> allCase = new ArrayList<>();
	static int visited[][];
	static int map[][];
	static int sol = 0;

	public static void generate(){
		threeByThreeGenerate();
		fourByfourGenerate();
		twoBytwoGenerate();
	}

	public static void threeByThreeGenerate(){
		int[][] a = {{1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
		int[][] b = {{0, 1, 0}, {1, 1, 0}, {1, 0, 0}};
		int[][] c = {{0, 1, 1}, {1, 1, 0}, {0, 0, 0}};
		int[][] d = {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}};
		int[][] e = {{1, 0, 0}, {1, 0, 0}, {1, 1, 0}};
		int[][] f = {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
		int[][] g = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
		int[][] h = {{1, 1, 1}, {1, 0, 0}, {0, 0, 0}};
		int[][] i = {{0, 1, 0}, {0, 1, 0}, {1, 1, 0}};
		int[][] j = {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}};
		int[][] k = {{1, 1, 0}, {1, 0, 0}, {1, 0, 0}};
		int[][] l = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
		int[][] m = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
		int[][] n = {{1, 0, 0}, {1, 1, 0}, {1, 0, 0}};
		int[][] o = {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}};
		int[][] p = {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}};
		threeByThree.add(a);
		threeByThree.add(b);
		threeByThree.add(c);
		threeByThree.add(d);
		threeByThree.add(e);
		threeByThree.add(f);
		threeByThree.add(g);
		threeByThree.add(h);
		threeByThree.add(i);
		threeByThree.add(j);
		threeByThree.add(k);
		threeByThree.add(l);
		threeByThree.add(m);
		threeByThree.add(n);
		threeByThree.add(o);
		threeByThree.add(p);
		allCase.add(threeByThree);
	}
	
	public static void fourByfourGenerate(){
		int [][] a = {{1, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0}};
		int [][] b = {{1, 1, 1, 1},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
		fourByfour.add(a);
		fourByfour.add(b);
		allCase.add(fourByfour);
	}

	public static void twoBytwoGenerate(){
		int [][] a = {{1, 1}, {1, 1}};
		twoBytwo.add(a);
		allCase.add(twoBytwo);
	}

	public static boolean applicable (int[][] tet, int r, int c){
		for (int i = 0; i < tet.length; i++) {
			for (int j = 0; j < tet[0].length ; j++){
				if (tet[i][j] == 1 && (r + i >= n || c + j >= m)){
					return false;
				}
			}
		}
		return (true);
	}

	public static void apply(int[][]tet, int r, int c){
		int sum = 0;
		for (int i = 0; i < tet.length; i++) {
			for (int j = 0; j < tet[0].length ; j++){
				if (tet[i][j] == 1){
					sum += map[r + i][c + j];
				}
			}
		}
		if (sol < sum){
//			System.out.println("found new !");
//			System.out.println("r, c : " + r + ", "+ c);
//			for (int i = 0; i < tet.length; i++) {
//				for (int j = 0; j < tet[0].length ; j++){
//					System.out.print(tet[i][j]);
//				}
//				System.out.println();
//			}
			sol = Integer.max(sum, sol);
		}
	}

	public static void dfs(){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				for (int case_i = 0; case_i < allCase.size(); case_i++) {
					ArrayList<int[][]> nByn = allCase.get(case_i);
					for (int tet_i = 0; tet_i < nByn.size(); tet_i++) {
						int[][] tet = nByn.get(tet_i);
						if (applicable(tet, i, j)){
							apply(tet, i, j);
						}
					}
				}
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		generate();

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visited = new int[n][m];
		generate();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
			}
//			System.out.println(Arrays.toString(map[i]));
		}
		dfs();
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
