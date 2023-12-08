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
		m = Integer.parseInt(st.nextToken());
		int k = m;
		int [] books = new int [n];
		PriorityQueue<Integer> plus =new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> minus =new PriorityQueue<>(Comparator.reverseOrder());
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			books[i] = Integer.parseInt(st.nextToken());
			if (books[i] < 0)
				minus.add(-books[i]);
			else
				plus.add(books[i]);
		}
		int sol = 0;
		int max = -1;
		while (plus.size() != 0){
			int book = plus.poll();
			m = k;
			max = Math.max(max, book);
			sol += book * 2;
			while (plus.size() != 0 && m > 1){
				plus.poll();
				m--;
			}
		}
		while (minus.size() != 0){
			int book = minus.poll();
			m = k;
			max = Math.max(max, book);
			sol += book * 2;
			while (minus.size() != 0 && m > 1){
				minus.poll();
				m--;
			}
		}
//		Arrays.sort(books);
//		System.out.println(Arrays.toString(books));
		System.out.println((sol - max));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


