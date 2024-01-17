import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int sol;
	static int maxChance = 2;
	public static void rec(String str, int l, int r, int chance){
		if (sol <= 1 || chance >= maxChance){
			return;
		}
		while (l <= r){
			if (str.charAt(l) != str.charAt(r)){
//				if (chance == 1)
//					break;
//				System.out.println("new try : " + str.substring(l + 1, r + 1));
				rec(str, l + 1, r, chance + 1);
//				System.out.println("new try : " + str.substring(l, r));
				rec(str, l, r - 1, chance + 1);
//				break;
			}
			l++;
			r--;
		}
		if (l > r){
			sol = Integer.min(sol, chance);
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			int curChance = 0;
			sol = Integer.MAX_VALUE;
			int l = 0, r = str.length() - 1;
			rec(str, l, r, curChance);
			sol = Integer.min(sol, 2);
			System.out.println(sol);
		}
		return ;
	}
}
