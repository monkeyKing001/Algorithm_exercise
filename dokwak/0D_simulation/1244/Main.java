import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static boolean sw[];

	public static void boy(int point){
		for (int i = 1; i <= n; i++) {
			int nextPoint = i * point;
			if (nextPoint > n)
				break;
			sw[nextPoint] = true ^ sw[nextPoint];
		}
	}

	public static void girl(int point){
		sw[point] = true ^ sw[point];
		int l = point - 1; 
		int r = point + 1;
		while (l >= 1 && r <= n && sw[l] == sw[r]){
			sw[l] = true ^ sw[l];
			sw[r] = true ^ sw[r];
			l--;
			r++;
		}
	}

	public static void action (int sex, int point){
		if (sex == 1)
			boy(point);
		else if (sex == 2)
			girl(point);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		sw = new boolean[n + 1];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 1; i <= n; i++) {
			int num = Integer.parseInt(st.nextToken());
			sw[i] = (num == 1);
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int sex = Integer.parseInt(st.nextToken());
			int point = Integer.parseInt(st.nextToken());
			action(sex, point);
		}
		int line = 1;
		for (int i = 1; i <= n; i++) {
			if (i > line * 20){
				System.out.println();
				line++;
			}
			if (sw[i])
				System.out.print("1 ");
			else
				System.out.print("0 ");
		}
		System.out.println();
		return ;
	}
}


