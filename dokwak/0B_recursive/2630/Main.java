import java.util.*;
import java.io.*;

public class Main{
	public static int [][] paper;
	public static int []dr = {1, 0};
	public static int []dc = {0, 1};
	public static int b = 0;
	public static int w = 0;
	public static int n = 0;

	static void rec(int start_r, int start_c, int size)
	{
		int current_c = paper[start_r][start_c];
		int [] cur = new int [2];
		cur[0] = start_r;
		cur[1] = start_c;
		boolean perfect = true;
		
		for (int i = start_r; i < size + start_r && perfect == true; i++) {
			for (int j = start_c; j < size + start_c && perfect == true; j++) {
				if (paper[i][j] == current_c)
					continue ;
				else
				{
					perfect = false;
					int next_size = size / 2;
					rec(start_r, start_c, next_size);
					rec(start_r + next_size, start_c, next_size);
					rec(start_r, start_c + next_size, next_size);
					rec(start_r + next_size, start_c + next_size, next_size);
				}
			}
		}
		if (perfect == true)
		{
			if (current_c == 1)
				b++;
			else if (current_c == 0)
				w++;
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		paper = new int [129][129];

		//input
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				int color = Integer.parseInt(st.nextToken());
				paper[i][j] = color;
			}
		}
		int size = n;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				System.out.print(paper.get(i).get(j) + " ");
//			}
//			System.out.print("\n");
//		}
		rec(0, 0, size);
		System.out.println(w);
		System.out.println(b);
		return ;
	}
}
