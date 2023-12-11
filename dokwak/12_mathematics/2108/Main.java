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
		ArrayList<Integer> arr = new ArrayList<>();
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			map.put(m, map.getOrDefault(m, 0) + 1);
			arr.add(m);
		}
		List<Integer> keySet = new ArrayList<>(map.keySet());
		keySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));
		List<Integer> mostFreqCandi = new ArrayList<>();
		int mostFreqNum = -1;
		for (Integer key: keySet) {
			mostFreqNum = key;
			break;
		}
		for (Integer key: keySet) {
			if (map.get(mostFreqNum) == map.get(key))
				mostFreqCandi.add(key);
		}
		mostFreqCandi.sort(Comparator.naturalOrder());
		arr.sort(Comparator.naturalOrder());
		IntSummaryStatistics sta = arr.stream().mapToInt(num -> num).summaryStatistics();
		double avg = sta.getAverage(); 
		avg = (int)Math.round(avg);
		int min = arr.get(0);
		int max = arr.get(arr.size() - 1);
		int mean = arr.get(arr.size() / 2);
		int freq = mostFreqCandi.get(0);
		if (mostFreqCandi.size() > 1)
			freq = mostFreqCandi.get(1);
		sb.append((int)avg);
		sb.append("\n");
		sb.append(mean);
		sb.append("\n");
		sb.append(freq);
		sb.append("\n");
		sb.append(max - min);
		sb.append("\n");
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


