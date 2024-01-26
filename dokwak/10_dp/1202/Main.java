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
		m = Integer.parseInt(st.nextToken());
		int jewNum = n;
		int bagNum = m;
		TreeMap<Integer, Integer> bags = new TreeMap<>();
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] e1, int [] e2){
				if (e1[1] == e2[1])
					return (Integer.compare(e1[0], e2[0]));
				return (Integer.compare(e2[1], e1[1]));
			}
		});
		for (int i = 0; i < jewNum; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int weight = Integer.parseInt(st.nextToken());
			int value = Integer.parseInt(st.nextToken());
			int info[] = new int[2];
			info[0] = weight;
			info[1] = value;
			pq.add(info);
		}
//		for (int i = 0; i < n; i++) {
//			System.out.println(Arrays.toString(jewerly.get(i)));
//		}
		for (int i = 0; i < bagNum; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int maxWeight = Integer.parseInt(st.nextToken());
			bags.put(maxWeight, bags.getOrDefault(maxWeight, 0) + 1);
		}
		long sol = 0;
		while (pq.size() != 0 && bags.size() != 0){
			int info [] = pq.poll();
			int weight = info[0];
			int value = info[1];
//			System.out.println("polling : " + Arrays.toString(info));
			if (bags.ceilingKey(weight) != null){
				int key = bags.ceilingKey(weight);
				if (bags.get(key) == 1){
					bags.remove(key);
				}
				else
					bags.put(key, bags.get(key) - 1);
//				System.out.println("found bag : " + bags.ceiling(weight));
				sol += (long)value;
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
