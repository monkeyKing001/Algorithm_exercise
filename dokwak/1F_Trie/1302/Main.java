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
		Map<String, Integer> map = new TreeMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			String book = br.readLine();
			map.put(book, map.getOrDefault(book, 0) + 1);
		}
		List<Map.Entry<String, Integer>>keySet = new ArrayList<>(map.entrySet());
		keySet.sort(Map.Entry.comparingByValue());
		int max = keySet.get(keySet.size() - 1).getValue();
		String book = keySet.get(keySet.size() - 1).getKey();
		for (int i = keySet.size() - 1; i > -1; i--) {
			if (keySet.get(i).getValue() != max)
				break;
			if (keySet.get(i).getKey().compareTo(book) < 0){
				book = keySet.get(i).getKey();
			}
		}
		sb.append(book);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


