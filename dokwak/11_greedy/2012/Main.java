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
		Set<Integer> s = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			s.add(i + 1);
		}
		ArrayList<Integer> not_grd = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(br.readLine());
			if (s.contains(temp))
				s.remove(temp);
			else
				not_grd.add(temp);
		}
		not_grd.sort(Comparator.naturalOrder());
		long sol = 0;
		int i = 0;
		Iterator<Integer> it = s.iterator();
		while(it.hasNext())
		{
			int num = not_grd.get(i);
			int grade = it.next();
			sol += Math.abs(num - grade);
			i++;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


