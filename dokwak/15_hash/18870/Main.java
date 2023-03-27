import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(br.readLine());
		int []org_arr = new int[n];
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		TreeSet<Integer> set = new TreeSet<Integer>();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			org_arr[i] = num;
			set.add(num);
		}
		int count = 0;
		Iterator<Integer> it = set.iterator();
		while (it.hasNext())
		{
			map.put(it.next(), count++);
		}
		for (int i = 0; i < n; i++) {
			org_arr[i] = map.get(org_arr[i]);
		}
		for (int i = 0; i < n; i++) {
			sb.append(org_arr[i] + " ");
		}
		System.out.print(sb);
//		for (int i = 0; i < n; i++) {
//			System.out.print(org_arr[i] + " ");
//		}
		return ;
	}
}

