import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 1000000;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		char [] origin = br.readLine().toCharArray();
		char [] target = br.readLine().toCharArray();
		char [] origin2 = origin.clone();
		for (int i = 0; i < 2; i++) {
			origin2[i] = (origin2[i] == '1') ? '0' : '1';
		}
//		System.out.println("start!");
//		System.out.println("origin : " + Arrays.toString(origin));
//		System.out.println("origin2 : " + Arrays.toString(origin2));
		
		int count1 = 0;
		int count2 = 1;
		int mid = 1;
		while (mid <= n - 1){
			//switch turn
			if (origin[mid - 1] != target[mid - 1]){
				for (int i = -1; i < 2 && mid + i < n; i++) {
					origin[mid + i] = (origin[mid + i] == '1') ? '0' : '1';
				}
//				System.out.println("swithc at " + mid);
//				System.out.println("origin : " + Arrays.toString(origin));
				count1++;
			}
			if (origin2[mid - 1] != target[mid - 1]){
				for (int i = -1; i < 2 && mid + i < n; i++) {
					origin2[mid + i] = (origin2[mid + i] == '1') ? '0' : '1';
				}
//				System.out.println("swithc at " + mid);
//				System.out.println("origin2 : " + Arrays.toString(origin2));
				count2++;
			}
			//leave it
			mid++;
		}
		if (origin[n - 1] != target[n - 1])
			count1 = Integer.MAX_VALUE;
		if (origin2[n - 1] != target[n - 1])
			count2 = Integer.MAX_VALUE;
		int sol = Integer.min(count1, count2);
		if (sol == Integer.MAX_VALUE)
			sol = -1;
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
