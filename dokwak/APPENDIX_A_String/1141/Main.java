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
		ArrayList<String> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			String str = st.nextToken();
			arr.add(str);
		}
		arr.sort(null);
//		for (int i = 0; i < arr.size(); i++) {
//			String str = arr.get(i);
//			sb.append(str + ", ");
//		}
//		sb.append("\n");
		Set<String> set = new HashSet<String>();
		for (int i = 0; i < arr.size(); i++) {
			String str = arr.get(i);
			if (i == arr.size() - 1 || !arr.get(i + 1).startsWith(str)) {
				set.add(str);
//				sb.append("prefix free : " + str);
//				sb.append("\n");
			}
		}
		sb.append(set.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


