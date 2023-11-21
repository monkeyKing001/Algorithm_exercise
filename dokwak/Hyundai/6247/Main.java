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
		st = new StringTokenizer(br.readLine()," ");
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		arr.sort(Comparator.naturalOrder());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int target = Integer.parseInt(st.nextToken());
			int idx = Collections.binarySearch(arr, target);
			if (idx < 0){
				sb.append("0");
			}
			else{
				sb.append((idx * (arr.size() - idx - 1)));
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


