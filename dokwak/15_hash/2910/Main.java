import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str," ");

		//input
		Map<Integer, Integer> map = new HashMap<>();
		Map<Integer, Integer> orderMap = new HashMap<>();
		ArrayList<Integer> arr = new ArrayList<>();
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		str = br.readLine();
		st = new StringTokenizer(str," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			map.put(num, map.getOrDefault(num, 0) + 1);
			orderMap.put(num, Integer.min(orderMap.getOrDefault(num, 1001), orderMap.size()));
			arr.add(num);
		}
		arr.sort(new Comparator<Integer>(){
			@Override
			public int compare (Integer a, Integer b){
				if (map.get(a) == map.get(b)){
					return (Integer.compare(orderMap.get(a), orderMap.get(b)));
				}
				return (Integer.compare(map.get(b), map.get(a)));
			}
		});
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
//		ArrayList<Map.Entry<Integer, Integer>> entries = new ArrayList<>(map.entrySet());
//		entries.sort(Map.Entry.comparingByValue());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
