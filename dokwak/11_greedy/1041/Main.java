import java.util.*;
import java.io.*;

public class Main{
	static long n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		ArrayList<Long> arr = new ArrayList<>();
		for (int i = 0; i < 6; i++) {
			int num = Integer.parseInt(st.nextToken());
			long numL = (long)num;
			arr.add(numL);
		}
		long oneD = Long.MAX_VALUE;
		for (int i = 0; i < 6; i++) {
			oneD = Long.min(oneD, arr.get(i));
		}
		long twoD = Long.MAX_VALUE;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (i == j || i + j == 5)
					continue;
				twoD = Long.min(twoD, arr.get(i) + arr.get(j));
			}
		}
		long thrD = Long.MAX_VALUE;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (i ==j || j ==k || i == k || i + j == 5 || j + k == 5 || i + k == 5)
						continue;
					thrD = Long.min(thrD, arr.get(i) + arr.get(j) + arr.get(k));
//					System.out.print(arr.get(i) + ", ");
//					System.out.print(arr.get(j) + ", ");
//					System.out.print(arr.get(k));
//					System.out.println();
				}
			}
		}
		long sol = 0;
		if (n == 1){
			for (int i = 0; i < 6; i++) {
				sol+= arr.get(i);
			}
			sol -= Collections.max(arr);
		}
		else{
			sol += 4 * thrD;
			sol += twoD * (n - 1) * 4;
			if (n >= 3){
				sol += (n - 2) * twoD * 4;
				sol += (((n - 2) * (n - 2) * (long)5) + ((n - 2) * (long)4)) * oneD;
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


