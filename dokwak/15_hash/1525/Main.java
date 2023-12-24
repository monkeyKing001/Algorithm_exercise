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
		ArrayList<Integer> arr = new ArrayList<>();
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			set.add(num);
			arr.add(num);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


