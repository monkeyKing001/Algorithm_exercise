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
		int [] arr = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		int oddCount = 0;
		int maxDiv2Count = 0;
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			int temp = 0;
			while (num > 0){
				if (num % 2 != 0){
					num--;
					oddCount++;
				}
				else{
					num /= 2;
					temp++;
				}
			}
			maxDiv2Count = Integer.max(maxDiv2Count, temp);
		}
		System.out.println(oddCount + maxDiv2Count);
	}
}
