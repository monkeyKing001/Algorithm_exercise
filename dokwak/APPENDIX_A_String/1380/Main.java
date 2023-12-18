import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		String input = br.readLine();
		int scinario = 1;
		while (input.compareTo("0") != 0){
			StringTokenizer st = new StringTokenizer(input," ");
			n = Integer.parseInt(st.nextToken());
			Map<String, Integer> map = new HashMap<String, Integer>();
			Map<Integer, String> idxMap = new HashMap<Integer, String>();
			for (int i = 0; i < n; i++) {
				String name = br.readLine();
				map.put(name, 0);
				idxMap.put(i + 1, name);
			}
			for (int i = 0; i < (2 * n) - 1; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int idx = Integer.parseInt(st.nextToken());
				String name = idxMap.get(idx);
				map.put(name, map.get(name) + 1);
			}
			List<Map.Entry<String, Integer>> check = new ArrayList<>(map.entrySet());
			check.sort(Map.Entry.comparingByValue());
			sb.append(scinario + " " + check.get(0).getKey() + "\n");
			scinario++;
			input = br.readLine();
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


