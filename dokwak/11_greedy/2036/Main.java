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
		PriorityQueue<Integer> plus = new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> minus = new PriorityQueue<>();
		PriorityQueue<Integer> zero = new PriorityQueue<>();
		PriorityQueue<Integer> one = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			if (num > 1)
				plus.add(num);
			else if (num == 1)
				one.add(num);
			else if (num == 0)
				zero.add(num);
			else
				minus.add(num);
		}
		long sol = 0;
		while (plus.size() != 0){
			long num = (long)plus.poll();
			if (plus.size() != 0){
				num *= (long)plus.poll();
			}
			sol += num;
		}
		while (minus.size() != 0){
			long num = (long)minus.poll();
			if (minus.size() != 0){
				num *= (long)minus.poll();
			}
			else if (zero.size() != 0){
				num = 0;
				zero.poll();
			}
			sol += num;
		}
		while (one.size() != 0){
			sol += one.poll();
		}
		System.out.println(sol);
		return ;
	}
}
