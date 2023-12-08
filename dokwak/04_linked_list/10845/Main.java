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
		Deque<Integer> arr = new ArrayDeque<>();
		for (int i = 0; i < n; i++) {
			arr.add(i + 1);
		}
		while (arr.size() != 1){
			arr.removeFirst();
			int first = arr.removeFirst();
			arr.add(first);
		}
		sb.append(arr.getFirst());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


