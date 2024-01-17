import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static Map<Character, Integer> score = new HashMap<Character, Integer>();
	public static int strToInt(String str){
		int ret = 0;
		return (ret);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<String> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int chr_i = 0; chr_i < str.length(); chr_i++) {
				char chr = str.charAt(chr_i);
				score.put(chr, score.getOrDefault(chr, 0) + (int)Math.pow(10, str.length() - 1 - chr_i));
			}
			arr.add(str);
		}
		ArrayList<Map.Entry<Character, Integer>> keySet = new ArrayList<>(score.entrySet());
		keySet.sort(Map.Entry.comparingByValue());
		int sum = 0;
		int digit = 9;
		for (int i = 0; i < keySet.size(); i++) {
			int score = keySet.get(keySet.size() - 1 - i).getValue() * digit;
			sum += score;
			digit--;
		}
		System.out.println(sum);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


