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
		int total = 0;
		TreeMap<String, Integer> map = new TreeMap<>();
		String tree = br.readLine();
		while (tree != null)
		{
			total++;
			if (map.containsKey(tree))
				map.replace(tree, map.get(tree) + 1);
			else
				map.put(tree, 1);
			tree = br.readLine();
		}
		int len = map.size();
		for (int i = 0; i < len; i++) {
			String temp = map.firstKey();
			double num = map.get(temp) * 100;
			double por = num / total;
			sb.append(temp + " ");
			String form = String.format("%.4f", por);
			sb.append(form + "\n");
			map.remove(temp);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
