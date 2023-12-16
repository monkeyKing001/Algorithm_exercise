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
		Set<String> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String id = br.readLine();
			arr.add(id);
		}
		int len = arr.get(0).length();
		for (int lastK = 1; lastK <= len; lastK++) {
			set.clear();
			for (int i = 0; i < n; i++) {
				String id = arr.get(i);
				String substr = id.substring(len - lastK, len);
				if (set.contains(substr))
					break;
				set.add(substr);
			}
			if (set.size() == arr.size()) {
				sb.append(lastK);
				break;
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


