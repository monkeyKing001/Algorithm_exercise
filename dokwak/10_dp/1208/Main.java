import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int [][] dp = new int [41][41];
	static long sol = 0;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int target = Integer.parseInt(st.nextToken());
		int mid = n / 2;
		ArrayList<Integer> left = new ArrayList<>();
		ArrayList<Integer> right = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < mid; i++) {
			int num = Integer.parseInt(st.nextToken());
			left.add(num);
		}
		for (int i = mid; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			right.add(num);
		}
		TreeMap<Integer, Integer> map = new TreeMap<>();
		for (int i = 0; i < (1 << left.size()); i++) {
			int temp_sum = 0;
			for (int j = 0; j < left.size(); j++) {
				if ((i & (1 << j)) != 0)//hits
					temp_sum += left.get(j);
			}
			if (map.containsKey(temp_sum))
			{
				map.replace(temp_sum, map.get(temp_sum) + 1);
//				System.out.println("plus key, num : " + temp_sum + map.get(temp_sum));
			}
			else
			{
				map.put(temp_sum, 1);
//				System.out.println("adding : "+ temp_sum);
			}
		}
		long sol = 0;
		for (int i = 0; i < (1 << right.size()); i++) {
			int temp_sum = 0;
			for (int j = 0; j < right.size(); j++) {
				if ((i & (1 << j)) != 0)
					temp_sum += right.get(j);
			}
			if (map.containsKey(target - temp_sum) == true)
			{
//				System.out.println("found key in map. key : " + (target - temp_sum));
				sol += map.get(target - temp_sum);
			}
		}
		if (target == 0)
			sol--;
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
