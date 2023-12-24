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
			String file = br.readLine();
			st = new StringTokenizer(file,".");
			String name = st.nextToken();
			String ext = st.nextToken();
			map.put(ext, map.getOrDefault(ext, 0) + 1);
		}
		for (String ext : map.keySet()){
			System.out.println(ext + " " + map.get(ext));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


