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
		Map<Character, Long> map = new HashMap<Character, Long>();
		ArrayList<String> strArr = new ArrayList<>();
		Set<Character> startChar = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			strArr.add(str);
			int len = str.length();
			for (int j = 0; j < str.length(); j++) {
				char chr = str.charAt(j);
				map.put(chr, (map.getOrDefault(chr, (long)0) + (long)Math.pow(10, len - j - 1)));
				if (j == 0)
					startChar.add(chr);
			}
		}
		List<Map.Entry<Character, Long>> keySet = new ArrayList<Map.Entry<Character, Long>>(map.entrySet());
		keySet.sort(Map.Entry.comparingByValue());
		Deque<Map.Entry<Character, Long>> deq = new ArrayDeque<>(keySet);
		//fix zero problem
		if (deq.size() == 10){
			char zeroCandidate = deq.getFirst().getKey();
//			sb.append(zeroCandidate);
//			sb.append(" cannot be zero!\n");
			//move zeor
			if (startChar.contains(zeroCandidate)){
				Iterator<Map.Entry<Character, Long>> it = deq.iterator();
				it.next();
				while (it.hasNext()){
					Map.Entry<Character, Long> ent = it.next();
					char canBeZero = ent.getKey(); 
					if (!startChar.contains(canBeZero)){
						//switch
//						sb.append(canBeZero);
//						sb.append(" can be zero!\n");
						deq.remove(ent);
						deq.addFirst(ent);
						break;
					}
				}
			}
		}
		long sum = 0;
		int digit = 9;
		while (deq.size() != 0){
			Map.Entry<Character, Long> ent = deq.removeLast();
			char key = ent.getKey();
			long value = ent.getValue();
//			sb.append("key, value : " + key + ", " + value + "\n");
			sum += value * digit;
			digit--;
		}
		sb.append(sum);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


