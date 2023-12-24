import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int visited[];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<Long> arr = new ArrayList<>();
		ArrayList<Long> twoSum = new ArrayList<>();
		Set<Long> twoSumSet = new HashSet<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			arr.add((long)num);
		}
		arr.sort(null);
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i; j < arr.size() ; j++){
				long sum = arr.get(i) + arr.get(j);
				twoSumSet.add(sum);
				twoSum.add(sum);
			}
		}
		long max = -1;
		for (int i = arr.size() - 1; i >= 0; i--) {
			for (int j = i; j >= 0; j--){
				long sum = arr.get(i);
				long target = sum - arr.get(j);
				//hash search
				if (twoSumSet.contains(target))
					max = Long.max(max, sum);
				//binart search
				if (Collections.binarySearch(twoSum, sum) > -1){
					max = Long.max(max, sum);
				}
			}
		}
		System.out.println(max);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
