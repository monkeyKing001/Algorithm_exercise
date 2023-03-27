import java.util.*;
import java.io.*;

public class Main{
	boolean cmp(String s1, String s2)
	{
		return (s1.compareTo(s2) <= 0);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int n = 0;
		int m = 0;
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<String> not_hear = new ArrayList<>();
		ArrayList<String> not_seen = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String name = br.readLine();
			not_hear.add(name);
		}
		for (int i = 0; i < m; i++) {
			String name = br.readLine();
			not_seen.add(name);
		}
		int ans = 0;
		not_hear.sort(Comparator.naturalOrder());
		not_seen.sort(Comparator.naturalOrder());
		ArrayList<String> ans_name = new ArrayList<>();
		int j = 0;
		for (int i = 0; i < not_hear.size(); i++) {
			String target = not_hear.get(i);
			for (; j < not_seen.size() && not_seen.get(j).compareTo(target) <= 0; j++)
			{
				String cmp = not_seen.get(j);
				if (target.compareTo(cmp) == 0)
				{
					ans++;
					ans_name.add(target);
					break ;
				}
			}
		}
		System.out.println(ans);
		for (int i = 0; i < ans_name.size(); i++) {
			System.out.println(ans_name.get(i));
		}

		//input
		//n = Integer.parseInt(st.nextToken());
		return ;
	}
}

